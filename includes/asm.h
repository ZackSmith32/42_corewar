/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:31:49 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/19 15:58:47 by kdavis           ###   ########.fr       */
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


typedef struct	s_label
{
	char		*name;
	union u_val	address;
}				t_label;

/*
** t_reading is a struct that holds the file we are reading as well as the current
** position of our parsing in the file.
**
** file:	vector containing the input file as a string
** labels:	vector containing pointers to the t_label struct
** cp:		char pointer to the current position in the file
*/

typedef struct s_reading
{
	t_vec		file;
	t_vec		labels;
	char		*cp;
}				t_reading;

/*
** t_asm is a master struct that holds information that we will need to use throughout
** 		the program
**
** header:	header struct comtaining magic, name, prog_size, comment
** input:	The input file and current reading thread
** output:	vector containing the byte code array
** name:	Name of the output file
*/

typedef struct	s_asm
{
	header_t	header;
	t_reading	input;
	t_vec		output;
	char		*name;
}				t_asm;

int			asm_error(t_asm *master, int ern);

/*
** endian_switch.c
*/
uint8_t		flip_uint8(uint8_t nbr);
uint32_t	flip_uint32(uint32_t nbr);
uint32_t	flip_uint64(uint64_t nbr);

/*
** skip_padding.c
*/
char	*next_token(char *cp);

/*
** read_header.c
*/
int	read_name(t_asm *master);
int	read_header(t_asm *master);

/*
** File parsing operations
**
**	Need functions for parsing each command type.
*/

#endif
