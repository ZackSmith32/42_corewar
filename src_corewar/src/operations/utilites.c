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

int			move_one(struct s_game *game, struct s_process *process)
{
	move_pc(game->arena, &process->pc, 1);
	ft_printf("moving one\n");
	return (0);
}

void		move_pc(uint8_t *arena, uint8_t **pc, int move)
{
	move = move % MEM_SIZE;
	*pc += move;
	if (*pc < arena)
		*pc += MEM_SIZE;
	else if (*pc > arena + MEM_SIZE)
		*pc -= MEM_SIZE;
}