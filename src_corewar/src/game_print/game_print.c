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

static void		simple_dump(uint8_t *arena, size_t size)
{
	uint8_t		*loc_conv;
	uint8_t		one;
	uint8_t		two;

	loc_conv = arena;
	while (size)
	{
		if (0 == size % OCTET_PER_LINE)
		{
			if (size != MEM_SIZE)
				ft_printf("\n");
			if (HEX_HEADER)
				ft_printf("0x%04x : ", MEM_SIZE - size);
		}
		two = 0x0F & *loc_conv;
		one = 0x0F & (*loc_conv >> 4);
		one = one > 9 ? one - 10 + 'a' : one + '0';
		two = two > 9 ? two - 10 + 'a' : two + '0';
		ft_printf("%c%c ", one, two);
		loc_conv++;
		size--;
	}
	ft_printf("\n");
}

static void		print_game_over(struct s_game *game)
{
	_Bool	pause;

	if ((g_flags.list & FLAG_P && attron(COLOR_PAIR(1)))
		|| g_flags.list & FLAG_V)
	{
		if ((pause = 1) && game->end_state == WINNER_CHOSEN)
			mvprintw(0, 0, "   Player %zu (%s) won :  %-20s",
				game->last_live_champ - game->champs + 1,
				game->last_live_champ->prog_name,
				game->last_live_champ->comment);
		refresh();
		while (pause)
			pause = (getch() == ' ') ? 0 : 1;
		endwin();
	}
	else
	{
		if (game->end_state == GAME_DUMP && g_flags.list & FLAG_D)
			simple_dump(game->arena, MEM_SIZE);
		else if (game->end_state == WINNER_CHOSEN)
			ft_printf("Player %zu (%s) won\n %s\n",
				game->last_live_champ - game->champs + 1,
				game->last_live_champ->prog_name,
				game->last_live_champ->comment);
	}
}

static void		keyhooks(void)
{
	int		key;
	clock_t		start;

	start = clock();
	mvprintw(0, 0, "%197s", " ");
	while (1000000 / g_flags.dump_per_second > clock() - start)
	{
		mvprintw(0, 0, "   %s%-4d%20s%-14d", "dump/sec[qwer]: ",
			(g_flags.dump_per_second),
			"skip[asdf/zxcv]: ", g_flags.cycle_intervals_to_dump);
		key = getch();
		win_resize();
		(key_pause(key) && (start = clock()))
			? printw("%s", "-paused-") : printw("%s", "*running*");
		key_wait(key);
		key_skip(key);
		key_rewind(key);
		key_scroll(key);
		refresh();
	}
	move(0, 195);
}

int				game_rewind(char **champ_files, struct s_game *game)
{
	unsigned int	target;

	target =
		(game->cycle_count > (unsigned int)(-g_flags.cycle_intervals_to_dump))
		? game->cycle_count + g_flags.cycle_intervals_to_dump : 0;
	free_game(game);
	if (-1 == init_game_struct(champ_files, game))
		return (-1);
	while (target)
	{
		if (-1 == game_step(game))
			return (-1);
		target--;
	}
	if (-1 == game_print(game))
		return (-1);
	return (0);
}

int				game_print(struct s_game *game)
{
	if ((g_flags.list & FLAG_P || g_flags.list & FLAG_V)
		&& (game->end_state != NOT_OVER || 0 >= g_flags.cycle_intervals_to_dump
			|| 0 == game->cycle_count % g_flags.cycle_intervals_to_dump))
	{
		if (g_flags.list & FLAG_P || game->end_state == GAME_DUMP)
			attrset(COLOR_PAIR(1));
		keyhooks();
		if (g_flags.list & FLAG_P || game->end_state == GAME_DUMP)
			print_hex(game->arena, game->arena_writer,
				MEM_SIZE, game->processes);
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
