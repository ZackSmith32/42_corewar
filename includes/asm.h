/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:31:49 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/25 21:44:28 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <corewar.h>

# define HEADER master->header
# define OUTPUT master->opp.output

/*
** Error macros:
*/

# define SYNTAX	-6
# define LEXICAL	-7
# define NAME_LONG -8
# define COMM_LONG -9

/*
** t_label holds the name and address of the labels found in the file
**
** name:	Name of the label
** address: Byte address of the label (used for when the label is referenced)
*/

typedef struct	s_label
{
	char		*name;
	int			address;
}				t_label;

/*
** t_label_calls is used to hold information on the label calls inside of ops
**
** name:	Name of the call
** op_addr:	Address of the op that the label is called in
** addr:	Address of the label call
** size:	Size of the label call (will vary based on the context of the call)
*/

typedef struct	s_label_calls
{
	char		*name;
	int			op_addr;
	int			addr;
	int			size;
}				t_label_calls;

/*
** name_cmd_len:	string length of the name command
** comment_cmd_len:	string length of the comment command
** commands_checked:flag for checking if a command has been activated before
**					bit: 1 == comment command
**					bit: 2 == name command
*/

typedef struct	s_cmdinfo
{
	size_t		name_cmd_len;
	size_t		comment_cmd_len;
	int			commands_checked;
}				t_cmdinfo;

/*
** fd:	File descriptor of the input file
** row: Current row being parsed
** col: Current column position of the parser
*/

typedef struct	s_parseinfo
{
	int			fd;
	int			row;
	int			col;
}				t_parseinfo;

/*
** op_parsing holds the vectors used during operation parsing
*/

typedef struct	s_op_parse
{
	t_vec		label_calls;
	t_vec		output;
}				t_op_parse;

/*
** t_asm is a master struct that holds information that we will need to use
**		throughout the program
**
** header:		Header struct comtaining magic, name, prog_size, comment
** cmd_info:	Holds information about the commands (such as string length)
** pi (parse):	Holds information on the input, and the current parsing location
** opp:			Holds label_calls and output which are used for op parsing
** labels:		List of labels located in the input file
** label_calls:	List of label called inside of the operations
** output:		Vector containing the byte code array
** name:		Name of the output file
*/

typedef struct	s_asm
{
	header_t	header;
	t_cmdinfo	cmd_info;
	t_parseinfo	pi;
	t_op_parse	opp;
	t_vec		labels;
	char		*name;
}				t_asm;

/*
** error
*/

int				print_error(int ern, char *str, int row, int col);
int				asm_error(t_asm *master, int ern);

/*
** endian_switch.c
*/
uint8_t			flip_uint8(uint8_t nbr);
uint32_t		flip_uint32(uint32_t nbr);
uint32_t		flip_uint64(uint64_t nbr);

/*
** line_parsing
*/

char			*skip_whitespaces(char *line);
int				is_labelchar(char c);
char			*skip_space_rev(char *line, int len);///

/*
** label
*/
char			*dup_label(char	**src, int *col);
int				parse_label(char *cp, t_asm *as, int depth);
int				new_label(t_vec *labels, char *name, int address);
t_label			*search_label(char *key, t_vec *labels);
int				fill_labels(t_vec *labels, t_vec *label_calls, t_vec *output);

/*
** op
*/
char			**delete_grid(char **grid);
int				parse_op(char *label, char *line, t_asm *as);
int				search_op(char *name);
int				write_op(int op_code, char *line, t_op_parse *opp);
char			**validate_parameters(const t_op *op, char *line, char *encode);
int				validate_atointmax(intmax_t *ret, char *str);
char			*load_byte_code(intmax_t value, int size);
int				add_param(const t_op *op, t_vec *output, char *param);
int				add_label_call(const t_op *op, t_op_parse *op_prs, int op_addr,
					char *param);
/*
** read_header
*/
int				read_header(t_asm *as);
int				read_command(header_t *header, char *line, t_parseinfo *pi,
					t_cmdinfo *info);
/*
** read_body
*/
int				read_body(t_asm *as);
int				parse_line(char	*head, t_asm *as, int depth);

#endif
