/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/05 13:46:56 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>
#include <op.h>

void		move_pc(uint8_t *arena, void **pc, int move)
{
	move = move % MEM_SIZE;
	*pc += move;
	if (*pc < arena)
		*pc += MEM_SIZE;
	else if (*pc > arena)
		*pc -= MEM_SIZE;
}
