/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:31:49 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/18 14:02:28 by kdavis           ###   ########.fr       */
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

typedef struct	s_asm
{
	header_t	header;
	t_vec		output;
	t_vec		file;
	char		*cp;
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
