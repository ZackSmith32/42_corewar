/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/05 12:21:34 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/*
** returns number of champs alive
*/

static unsigned int		lives_update_return_count(struct s_champ *champ,
															unsigned int count)
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

static void				step_processes(struct s_game *game)
{
	struct s_process	*p;
	size_t				i;
	void				(*op_pointer)(struct s_game*, struct s_process*);

	while ((p = (struct s_process *)ft_vecindex(game->processes, i)))
	{
		// operations execute at the end of their last cycle
		p->countdown--;
		if (p->countdown == 0)
		{	
			//TODO: call function and set pc
			// get function pointer from global array
			// assumes adding funciton pointer to g_op_tab
			// assumes adding next_op_code to s_process

			op_pointer = NULL;
			if (-1 == op_lookup(p->next_op_code, op_pointer))
				return (-1);
			op_pointer(game, p);
			p->next_op_code = *((int *)p->pc);
		}	
		i++;
	}
}

/*
**	Operation requirements:
**		> move PC
**		> update last_live_champ
**		> update countdown
**		> update cary
**		> update registries
*/

/*
**	If (end of game)
** 		> pick winner
**	else
**		> update cycles
*/

int						game_step(struct s_game *game)
{
	size_t		i;

	step_processes(game);
	i = 0;
	game->cycles_to_death--;
	if (game->cycles_to_death == 0)
	{
		if (game->cycles < CYCLE_DELTA
			|| lives_update_return_count(game->champs, game->champ_count) < 2)
			game->winner = pick_winner(game);
		else
		{
			game->cycles_max -= CYCLE_DELTA;
			game->cycles_to_death = game->cycles_max;
		}
	}
	return (0);
}
