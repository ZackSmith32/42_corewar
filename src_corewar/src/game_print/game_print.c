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

void		print_process(uint8_t *arena, struct s_process *process)
{
	size_t	i;

	ft_printf("  carry: %d", (int)process->carry);
	ft_printf("  pc: %4zu", (size_t)(process->pc - arena));
	ft_printf("  countdown: %04u", process->countdown);
	ft_printf("  op_code: %02u", process->op_code);
	ft_printf("  called_live: %u", process->called_live);
	i = 0;
	while (i < REG_NUMBER)
	{
		ft_printf("  r%zu: %hx", i, process->registors[i]);
		i++;
	}
}

void		print_processes(uint8_t *arena, t_list *processes)
{
	size_t	i;

	if (!(g_flags.verbosity_level & V_PROCESS))
		return ;
	i = 0;
	ft_putchar('\n');
	while (processes)
	{
		ft_printf("\n\033[%um\033[1mprocess %03zu\033[0m", i % 8 + 30, i);
		print_process(arena, processes->content);
		processes = processes->next;
		i++;
	}
}

void		print_game_state(struct s_game game)
{
	if (!(g_flags.verbosity_level & V_STATE))
		return ;
	ft_printf("\ncycles current/death:%4u/%4u\n  lives:%3u  last live: %s",
			game.current_cycles, game.cycles_to_death,
			game.lives, game.last_live_champ->prog_name);
}

int				game_print(struct s_game *game)
{
	if ((g_flags.list & FLAG_P || g_flags.list & FLAG_V)
			&& (0 == g_flags.cycle_intervals_to_dump
				|| 0 == game->current_cycles % g_flags.cycle_intervals_to_dump))
	{
		write(1, "\033c", 2);
		if (g_flags.list & FLAG_P)
			print_hex(game->arena, MEM_SIZE, game->processes);
		if (g_flags.list & FLAG_V)
		{
			print_game_state(*game);
			print_processes(game->arena, game->processes);
		}
		usleep(500);
	}
	return (0);
}