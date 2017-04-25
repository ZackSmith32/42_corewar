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

void		print_game_state(t_strvec *out, struct s_game *game)
{
	if (!(g_flags.verbosity_level & V_STATE))
		return ;
	ft_jasprintf(out,
			"\ncycles current/death:%4u/%4u  check count/max: %u/%u"
			"  lives:%3u  last_live_champ: %-32s",
			game->current_cycles, game->cycles_to_death,
			game->check_count, MAX_CHECKS,
			game->lives, game->last_live_champ->prog_name);
}

static void		print_game_over(t_strvec *out, struct s_game *game)
{
	(void)out;
		ft_printf("\033[2J\033[1;1HPlayer %zu (%s) won\n %s\n",
			game->last_live_champ - game->champs + 1,
			game->last_live_champ->prog_name,
			game->last_live_champ->comment);
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
	if (game->game_over)
		print_game_over(out, game);
	else if ((g_flags.list & FLAG_P || g_flags.list & FLAG_V)
			&& (0 == g_flags.cycle_intervals_to_dump
				|| 0 == game->current_cycles % g_flags.cycle_intervals_to_dump))
	{
		out->len = 0;
		ft_jasprintf(out, "\033[1;1H");
		if (g_flags.list & FLAG_P)
			print_hex(out, game->arena, MEM_SIZE, game->processes);
		if (g_flags.list & FLAG_V)
		{
			print_game_state(out, game);
			print_processes(out, game->arena, game->processes);
		}
		write(1, out->str, out->len);
		usleep(g_flags.wait_time);
	}
	return (0);
}
