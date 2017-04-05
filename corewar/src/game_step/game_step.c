/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/03/04 18:52:04 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/*
** returns number of champs alive
*/

static unsigned int		champ_state(struct s_champ *champ, unsigned int count)
{
	unsigned int	i;
	unsigned int	remaining;

	i = 0;
	remaining = 0;
	while (i < count)
	{
		if (champ[i].lives == 0)
			champ[i].alive = false;
		else if (champ[i].alive == true)
		{
			champ[i].lives = 0;
			remaining++;
		}
		i++;
	}
	return (remaining);
}

static struct s_champ	*pick_winner(struct s_game *game)
{
	unsigned int	i;

	i = 0;
	while (i < game->champ_count)
	{
		if (game->champs[i].alive == true)
			return (&game->champs[i]);
		i++;
	}
	return (game->last_live_champ);
}


int						game_step(struct s_game *game)
{
	struct s_process *p;
	size_t			i;

	i = 0;
	while ((p = (struct s_process *)ft_vecindex(game->processes, i)))
	{
		p->countdown--;
		if (p->countdown == 0)
		{			
			//TODO: call function and set pc
		}	
		i++;
	}
	game->cycles_to_death--;
	if (game->cycles_to_death == 0)
	{
		kill_players(game);
		game->cycles_max -= CYCLE_DELTA;
		game->cycles_to_death = game->cycles_max;
		if (champ_state(game->champs, game->champ_count) < 2)
			game->winner = pick_winner(game);
	}
	return (0);
}
