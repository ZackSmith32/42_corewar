/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:31:49 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/22 14:42:47 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <corewar.h>

#define HEADER master->header
#define OUTPUT master->output


/*
** Error macros:
*/

#define SYNTAX	-6
#define LEXICAL	-7
#define NAME_LONG -8
#define COMM_LONG -9

/*
** Command notes:
** 
**		Label_chars are the only valid characters for function names
*/

/*
** sti: 1st parameter may be indirect or direct, 2nd parameter must be indirect
*/

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
** name_cmd_len:	string length of the name command
** comment_cmd_len:	string length of the comment command
** commands_checked:flag for checking if a command has been activated before
**					bit: 1 == comment command
**					bit: 2 == name command
*/

typedef struct s_cmdinfo
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
** t_asm is a master struct that holds information that we will need to use throughout
** 		the program
**
** header:		Header struct comtaining magic, name, prog_size, comment
** cmd_info:	Holds information about the commands (such as string length)
** pi (parse):	Holds information on the input, and the current location in parsing
** labels:		List of labels located in the input file
** output:		Vector containing the byte code array
** name:		Name of the output file
*/

typedef struct	s_asm
{
	header_t	header;
	t_cmdinfo	cmd_info;
	t_parseinfo	pi;
	t_vec		labels;
	t_vec		label_calls;
	t_vec		output;
	char		*name;
}				t_asm;


/*
** error 
*/

int			print_error(int ern, char *str, int row, int col);
int			asm_error(t_asm *master, int ern);

/*
** endian_switch.c
*/
uint8_t		flip_uint8(uint8_t nbr);
uint32_t	flip_uint32(uint32_t nbr);
uint32_t	flip_uint64(uint64_t nbr);


/*
** line_parsing
*/

char	*skip_whitespaces(char *line);
char	*skip_space_rev(char *line, int len);
int		next_token(char **cp);

/*
** read_header
*/
int	read_header(t_asm *as);
int	read_command(header_t *header, char *line, t_parseinfo *pi, t_cmdinfo *info);

/*
** read_body
*/
int	read_body(t_asm *as);
int	is_labelchar(char c);
int	parse_label(char *cp, t_asm *as, int depth);
int	parse_line(char	*head, t_asm *as, int depth);

char	*dup_label(char	**src, int *col);
int		new_label(t_vec *labels, char *name, int address);
t_label	*search_label(char *key, t_vec *labels);

#endif
