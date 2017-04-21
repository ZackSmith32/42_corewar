/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		print_process(t_strvec *out, uint8_t *arena,
				struct s_process *process)
{
	size_t	i;

	ft_jasprintf(out, "  carry: %d", (int)process->carry);
	ft_jasprintf(out, "  pc: %3hx", (size_t)(process->pc - arena));
	ft_jasprintf(out, "  countdown: %04u", process->countdown);
	ft_jasprintf(out, "  op: %-6s", g_op_tab[process->op_code].name_short);
	ft_jasprintf(out, "  called_live: %u", process->called_live);
	i = 0;
	while (i < REG_NUMBER)
	{
		ft_jasprintf(out, "  r%zu: %hx", i + 1, process->registors[i]);
		i++;
	}
}

void		print_processes(t_strvec *out, uint8_t *arena, t_list *processes)
{
	size_t	i;

	if (!(g_flags.verbosity_level & V_PROCESS))
		return ;
	i = 0;
	while (processes)
	{
		ft_jasprintf(out, "\n\033[%um\033[1mprocess %03zu\033[0m",
			i % 7 + 31, i);
		print_process(out, arena, processes->content);
		processes = processes->next;
		i++;
	}
}

void		print_game_state(t_strvec *out, struct s_game *game)
{
	if (!(g_flags.verbosity_level & V_STATE))
		return ;
	ft_jasprintf(out,
			"\ncycles current/death:%4u/%4u  check count/max: %u/%u"
			"  lives:%3u  last_live_champ: %s",
			game->current_cycles, game->cycles_to_death,
			game->check_count, MAX_CHECKS,
			game->lives, game->last_live_champ->prog_name);
}

int			ft_jasprintf(t_strvec *ret, const char *format, ...)
{
	va_list		ap;
	int			size;

	va_start(ap, format);
	size = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (size);
}

int			game_print(struct s_game *game, t_strvec *out)
{
	if ((g_flags.list & FLAG_P || g_flags.list & FLAG_V)
			&& (0 == g_flags.cycle_intervals_to_dump
				|| 0 == game->current_cycles % g_flags.cycle_intervals_to_dump))
	{
		out->len = 0;
		ft_jasprintf(out, "\033[2J\033[1;1H\n");
		if (g_flags.list & FLAG_P)
			print_hex(out, game->arena, MEM_SIZE, game->processes);
		if (g_flags.list & FLAG_V)
		{
			print_game_state(out, game);
			print_processes(out, game->arena, game->processes);
		}
		write(1, out->str, out->len);
		usleep(1000000);
	}
	return (0);
}
