/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/05/04 16:46:08 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

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

static void				load_op(struct s_process *p)
{
	p->op_code = *p->pc;
	if (p->op_code >= NUMBER_OF_FUNCTIONS)
		p->op_code = 0;
	p->countdown = g_op_tab[p->op_code].cycles_required;
	p->needs_op_update = false;
}

static int				step_processes(struct s_game *game)
{
	t_list				*link;
	struct s_process	*p;

	link = game->processes;
	while (link && (p = link->content))
	{
		if (p->needs_op_update == true)
			load_op(p);
		p->countdown--;
		if (p->countdown == 0)
		{
			p->needs_op_update = true;
			if (-1 == g_op_pointers[p->op_code](game, p))
				return (-1);
		}
		link = link->next;
	}
	return (0);
}

static void				kill_processes(t_list **list)
{
	while (*list)
	{
		if (((struct s_process*)(*list)->content)->called_live == false)
		{
			lstdelone(list, &free);
		}
		else
		{
			((struct s_process*)(*list)->content)->called_live = false;
			list = &(*list)->next;
		}
	}
}

int						game_step(struct s_game *game)
{
	if (-1 == step_processes(game))
		return (-1);
	game->current_cycles++;
	game->cycle_count++;
	if (game->current_cycles == game->cycles_to_death)
	{
		kill_processes(&game->processes);
		if (game->lives >= NBR_LIVE || game->check_count >= MAX_CHECKS)
		{
			game->check_count = 0;
			if (game->processes == NULL || game->cycles_to_death <= CYCLE_DELTA)
				game->end_state = WINNER_CHOSEN;
			else
				game->cycles_to_death -= CYCLE_DELTA;
		}
		else
			game->check_count++;
		game->lives = 0;
		game->current_cycles = 0;
	}
	return (0);
}
