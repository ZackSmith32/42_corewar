/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:31:49 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/15 20:28:47 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <corewar.h>

/*
** Command notes:
** 
**		Label_chars are the only valid characters for function names
*/

/*
** sti: 1st parameter may be indirect or direct, 2nd parameter must be indirect
*/

void	asm_error(int ern, int fd);

#endif
