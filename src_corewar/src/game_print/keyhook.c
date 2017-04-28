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

void	win_resize(void)
{
	static int	h_prev;
	static int	w_prev;
	int			h;
	int			w;

	getmaxyx(stdscr, h, w);
	if (h != h_prev || w != w_prev)
	{
		clear();
		h_prev = h;
		w_prev = w;
	}
}

_Bool	key_pause(char key)
{
	static _Bool	pause;

	if (key == ' ')
		memxor(&pause, ~0, sizeof(pause));
	return(pause);
}

void	key_wait(char key)
{
	if (key == 'q')
		g_flags.wait_time = (g_flags.wait_time > 10000)
			? g_flags.wait_time - 10000 : 1000;
	else if (key == 'w')
		g_flags.wait_time = (g_flags.wait_time > 1000)
			? g_flags.wait_time - 1000 : 1000;
	else if (key == 'e')
		g_flags.wait_time = (g_flags.wait_time < 999000)
			? g_flags.wait_time + 1000 : 1000000;
	else if (key == 'r')
		g_flags.wait_time = (g_flags.wait_time < 990000)
			? g_flags.wait_time + 10000 : 1000000;
}

void	key_skip(char key)
{
	if (key == 'f')
		g_flags.cycle_intervals_to_dump = (g_flags.cycle_intervals_to_dump > 25)
			? g_flags.cycle_intervals_to_dump - 25 : 1;
	else if (key == 'd')
		g_flags.cycle_intervals_to_dump = (g_flags.cycle_intervals_to_dump > 1)
			? g_flags.cycle_intervals_to_dump - 1 : 1;
	else if (key == 's')
		g_flags.cycle_intervals_to_dump =
		(g_flags.cycle_intervals_to_dump < 1599)
			? g_flags.cycle_intervals_to_dump + 1 : 1600;
	else if (key == 'a')
		g_flags.cycle_intervals_to_dump =
			(g_flags.cycle_intervals_to_dump < 1575)
			? g_flags.cycle_intervals_to_dump + 25 : 1600;
}
