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
			"\ncycles: %-6u current/death:%4u/%4u  check count/max: %u/%u"
			"  lives:%3u  last_live_champ: ", game->cycle_count,
			game->current_cycles, game->cycles_to_death,
			game->check_count, MAX_CHECKS,
			game->lives);
	if (game->last_live_champ)
		attron(COLOR_PAIR(game->last_live_champ - game->champs + 10)
			| A_REVERSE);
	printw("%-30s", game->last_live_champ->prog_name);
	if (game->last_live_champ)
		attrset(A_NORMAL);
	printw("     aff: %-55s", game->aff_out.str);
	game->aff_out.len = 0;
}

void			simple_dump(uint8_t *arena, size_t size)
{
	uint8_t		*loc_conv;
	uint8_t		one;
	uint8_t		two;

	loc_conv = arena;
	while (size)
	{
		if (0 == size % OCTET_PER_LINE)
		{
			ft_printf("\n");
			if (HEX_HEADER)
				ft_printf("0x%04x : ", MEM_SIZE - size);
		}
		two = 0x0F & *loc_conv;
		one = 0x0F & (*loc_conv >> 4);
		one = one > 9 ? one - 10 + 'A' : one + '0';
		two = two > 9 ? two - 10 + 'A' : two + '0';
		ft_printf("%c%c ", one, two);
		loc_conv++;
		size--;
	}
	ft_printf("\n");
}

static void		print_game_over(struct s_game *game)
{
	_Bool	pause;

	if (g_flags.list & FLAG_P || g_flags.list & FLAG_V)
	{
		pause = 1;
		if (game->end_state != WINNER_CHOSEN)
		{
			attron(COLOR_PAIR(1));
			move(0, 0);
			printw("   Player %zu (%s) won :  %-20s",
				game->last_live_champ - game->champs + 1,
				game->last_live_champ->prog_name,
				game->last_live_champ->comment);
		}
		refresh();
		while (pause)
			if (getch() == ' ')
				pause = 0;
		attrset(A_NORMAL);
		endwin();
	}
	else if (game->end_state == WINNER_CHOSEN)
	{
		if (g_flags.list & FLAG_D)
			simple_dump(game->arena, MEM_SIZE);		
		ft_printf("Player %zu (%s) won\n %s\n",
			game->last_live_champ - game->champs + 1,
			game->last_live_champ->prog_name,
			game->last_live_champ->comment);
	}
	else if (game->end_state == GAME_DUMP)
		simple_dump(game->arena, MEM_SIZE);
}

static void		keyhooks(void)
{
	char		key;
	clock_t		start;

	start = clock();
	if (g_flags.list & FLAG_P)
		attron(COLOR_PAIR(1));
	mvprintw(0,0,"%197s", " ");
	while (g_flags.wait_time > clock() - start)
	{
		mvprintw(0, 0, "   %s%-4d%20s%-14d", "speed[qwer]: ",
			(1000000 - g_flags.wait_time) / 1000 + 1,
			"skip[asdf/zxcv]: ", g_flags.cycle_intervals_to_dump);
		key = getch();
		win_resize();
		if (key_pause(key) && (start = clock()))
			printw("%s", "-paused-");
		key_wait(key);
		key_skip(key);
		key_rewind(key);
		refresh();
	}
	move(0, 195);
}

int				game_rewind(char **champ_files, struct s_game *game)
{
	unsigned int	target;
	int				h;
	int				w;

	target =
		(game->cycle_count > (unsigned int)(-g_flags.cycle_intervals_to_dump))
		? game->cycle_count + g_flags.cycle_intervals_to_dump : 0;
	free_game(game);
	if (-1 == init_game_struct(champ_files, game))
		return (-1);
	game->cycle_count = target;
	while (target)
	{
		if (-1 == game_step(game))
			return (-1);
		target--;
	}
	if (-1 == game_print(game))
		return (-1);
	getmaxyx(stdscr, h, w);
	printw("%*s", h * w, " ");
	refresh();
	return (0);
}

int				game_print(struct s_game *game)
{
	if ((g_flags.list & FLAG_P || g_flags.list & FLAG_V)
		&& (game->end_state != NOT_OVER || 0 >= g_flags.cycle_intervals_to_dump
		|| 0 == game->cycle_count % g_flags.cycle_intervals_to_dump))
	{
		keyhooks();
		if (g_flags.list & FLAG_P)
			print_hex(game->arena, MEM_SIZE, game->processes);
		if (g_flags.list & FLAG_V)
		{
			print_game_state(game);
			print_processes(game->arena, game->processes);
		}
		refresh();
	}
	if (game->end_state != NOT_OVER)
		print_game_over(game);
	return (0);
}
