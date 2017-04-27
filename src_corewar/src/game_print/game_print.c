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

void			print_game_state(struct s_game *game)
{
	if (!(g_flags.verbosity_level & V_STATE))
		return ;
	printw(
			"\ncycles current/death:%4u/%4u  check count/max: %u/%u"
			"  lives:%3u  last_live_champ: ",
			game->current_cycles, game->cycles_to_death,
			game->check_count, MAX_CHECKS,
			game->lives);
	if (game->last_live_champ)
		attron(COLOR_PAIR(game->last_live_champ - game->champs + 10)
			| A_REVERSE);
	printw("%-100s", game->last_live_champ->prog_name);
	if (game->last_live_champ)
		attrset(A_NORMAL);
}

static void		print_game_over(struct s_game *game)
{
	ft_printf("\033[2J\033[1;1H");
	ft_printf("Player %zu (%s) won\n %s\n",
		game->last_live_champ - game->champs + 1,
		game->last_live_champ->prog_name,
		game->last_live_champ->comment);
}

static void		keyhooks()
{
	char		key;
	clock_t		start;

	start = clock();
	attron(COLOR_PAIR(1));
	while (g_flags.wait_time > clock() - start)
	{
		key = getch();
		win_resize();
		key_pause(key);
		key_wait(key);
		key_skip(key);
		move(0, 0);
		printw("   %s%-10d%20s%-143d", "speed[qwer]: ", 1000000 - g_flags.wait_time,
			"skip[asdf]: ", g_flags.cycle_intervals_to_dump);
		refresh();
	}
}

static int		print_init(void)
{
	keyhooks();
	move(0, 0);
	return (0);
}

int				game_print(struct s_game *game)
{
	if (game->game_over)
		print_game_over(game);
	else if ((g_flags.list & FLAG_P || g_flags.list & FLAG_V)
			&& (0 == g_flags.cycle_intervals_to_dump
				|| 0 == game->current_cycles % g_flags.cycle_intervals_to_dump))
	{
		print_init();
		if (g_flags.list & FLAG_P)
			print_hex(game->arena, MEM_SIZE, game->processes);
		if (g_flags.list & FLAG_V)
		{
			print_game_state(game);
			print_processes(game->arena, game->processes);
		}
		refresh();	
	}
	return (0);
}
