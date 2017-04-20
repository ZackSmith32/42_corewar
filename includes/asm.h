/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:31:49 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/19 21:30:16 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <corewar.h>

#define OUTPUT	master->output
#define HEADER	master->header

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
	uint32_t	address;
}				t_label;

typedef struct s_cmdinfo
{
	size_t		name_cmd_len;
	size_t		comment_cmd_len;
	int			commands_checked;
}				t_cmdinfo;

/*
** t_asm is a master struct that holds information that we will need to use throughout
** 		the program
**
** header:	header struct comtaining magic, name, prog_size, comment
** labels:	list of labels located in the input file
** output:	vector containing the byte code array
** name:	Name of the output file
*/

typedef struct	s_asm
{
	header_t	header;
	t_cmdinfo	cmd_info;
	t_vec		labels;
	t_vec		output;
	char		*name;
	int			fd;
	int			row;
	int			col;
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
int		next_token(char **cp);

/*
** read_header
*/
int	read_header(t_asm *as);
int	read_commands(header_t *header, char *line, int *col, t_cmdinfo *info);

#endif
