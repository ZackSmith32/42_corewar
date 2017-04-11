/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/11 14:37:22 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Live requirements:
**		x > update lives
**		x > update last_live_champ
**		x > move pc
*/

int		live(struct game *game, struct s_process *process)
{
	char			*pc;
	unsigned int	player_name;

	pc = (char *)process->pc;
	pc++;
	player_name = ~(unsigned int)pc;
	if (player_name > game->champ_count)
		return (-1);
	(game->champs[player_name]).lives++;
	game->last_live_champ = game->champs[player_name] 
	move_pc(&game->arena, &process->pc, 5);
	return (1);
}

int		ld(sturct game *game, struct s_process *process)
{
	char			*pc;

	pc = (char *)
}
