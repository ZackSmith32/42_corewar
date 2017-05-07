/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 11:41:32 by kdavis            #+#    #+#             */
/*   Updated: 2017/05/06 11:41:50 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			move_one(struct s_game *game, struct s_process *process)
{
	move_pc(game->arena, &process->pc, 1);
	return (0);
}
