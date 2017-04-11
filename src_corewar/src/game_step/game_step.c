/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/11 12:51:34 by zsmith           ###   ########.fr       */
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

/*
**	step_process:
**	
**	p = link->content = ??, what does the linked list do?
**	
**	for all processes
**		decrement countdown
**		if coutdown == 0
**			execute command (command will move process pointer forward)
**			add new op code to process
**			set countdown for new op_code
*/

static void				step_processes(struct s_game *game)
{
	t_list				*link;
	struct s_process	*p;

	link = game->processes;
	while (link && (p = link->content))
	{
		// operations execute at the end of their last cycle
		p->countdown--;
		if (p->countdown == 0)
		{	
			//TODO: call function and set pc
			// get function pointer from global array
			// assumes adding funciton pointer to g_op_tab
			// assumes adding op_code to s_process
			if (-1 == g_op_pointers[p->op_code](game, p))
			{
				//TODO: FUNCTION FAILER
			}
			p->op_code = *((int *)p->pc);
			if (p->op_code > NUMBER_OF_FUNCTIONS)
				p->op_code = 0;
			p->countdown = g_op_tab[p->op_code].cycles_required;
		}
	}
	link = link->next;
}

/*
**	Operation requirements:
**		> update last_live_champ
**		> update cary
**		> update registries
**		> *for live update lives
*/

/*
**	game_step:
**
**	updata processes
**	if (end of round aka cycles to death == 0)
** 		if (no more rounds possible)
**			pick winner
**		else
**			decrement cycles max and reset cycles to death
*/

int						game_step(struct s_game *game)
{
	step_processes(game);
	game->cycles_to_death--;
	if (game->cycles_to_death == 0)
	{
		if (game->cycles_max < CYCLE_DELTA
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
