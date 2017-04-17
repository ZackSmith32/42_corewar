/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/13 10:26:24 by zsmith           ###   ########.fr       */
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
				move_pc(game->arena, &p->pc, 1);
			}
			p->op_code = *p->pc;
			if (p->op_code > NUMBER_OF_FUNCTIONS)
				p->op_code = 0;
			p->countdown = g_op_tab[p->op_code].cycles_required;
		}
		link = link->next;
	}
}

static void					kill_processes(t_list **processes)
{
	t_list *tail;

	tail = *processes;
	while (*processes)
	{
		while (((struct s_process*)(*processes)->content)->called_live == false)
		{
			lstdelone(processes, &free);
		}
		processes = &(*processes)->next;
	}
}

int						game_step(struct s_game *game)
{
	step_processes(game);
	game->current_cycles++;
	if (game->current_cycles == game->cycles_to_death)
	{
		kill_processes(&game->processes);
		if (game->lives >= NBR_LIVE || game->check_count >= MAX_CHECKS)
		{
			game->check_count = 0;
			if (game->processes == NULL || game->cycles_to_death <= CYCLE_DELTA)
				game->game_over = true;
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
