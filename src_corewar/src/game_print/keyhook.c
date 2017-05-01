/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:44:34 by aphan             #+#    #+#             */
/*   Updated: 2017/05/01 15:44:42 by aphan            ###   ########.fr       */
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

_Bool	key_pause(int key)
{
	static _Bool	pause;

	if (key == ' ')
		pause--;
	return (pause);
}

void	key_wait(int key)
{
	if (key == 'q')
		g_flags.dump_per_second = (g_flags.dump_per_second > 10)
			? g_flags.dump_per_second - 10 : 1;
	else if (key == 'w')
		g_flags.dump_per_second = (g_flags.dump_per_second > 1)
			? g_flags.dump_per_second - 1 : 1;
	else if (key == 'e')
		g_flags.dump_per_second = (g_flags.dump_per_second < 999)
			? g_flags.dump_per_second + 1 : 1000;
	else if (key == 'r')
		g_flags.dump_per_second = (g_flags.dump_per_second < 990)
			? g_flags.dump_per_second + 10 : 1000;
}

void	key_skip(int key)
{
	if (key == 'a')
		g_flags.cycle_intervals_to_dump = (g_flags.cycle_intervals_to_dump > 25)
			? g_flags.cycle_intervals_to_dump - 25 : 1;
	else if (key == 's')
		g_flags.cycle_intervals_to_dump = (g_flags.cycle_intervals_to_dump > 1)
			? g_flags.cycle_intervals_to_dump - 1 : 1;
	else if (key == 'd')
	{
		if (g_flags.cycle_intervals_to_dump < 1)
			g_flags.cycle_intervals_to_dump = 1;
		else if (g_flags.cycle_intervals_to_dump < 1599)
			g_flags.cycle_intervals_to_dump += 1;
		else
			g_flags.cycle_intervals_to_dump = 1600;
	}
	else if (key == 'f')
	{
		if (g_flags.cycle_intervals_to_dump < 1)
			g_flags.cycle_intervals_to_dump = 25;
		else if (g_flags.cycle_intervals_to_dump < 1575)
			g_flags.cycle_intervals_to_dump += 25;
		else
			g_flags.cycle_intervals_to_dump = 1600;
	}
}

void	key_rewind(int key)
{
	if (key == 'z')
		g_flags.cycle_intervals_to_dump =
			(g_flags.cycle_intervals_to_dump < -25)
			? g_flags.cycle_intervals_to_dump + 25 : -1;
	else if (key == 'x')
		g_flags.cycle_intervals_to_dump = (g_flags.cycle_intervals_to_dump < -1)
			? g_flags.cycle_intervals_to_dump + 1 : -1;
	else if (key == 'c')
	{
		if (g_flags.cycle_intervals_to_dump > -1)
			g_flags.cycle_intervals_to_dump = -1;
		else if (g_flags.cycle_intervals_to_dump > -1599)
			g_flags.cycle_intervals_to_dump -= 1;
		else
			g_flags.cycle_intervals_to_dump = -1600;
	}
	else if (key == 'v')
	{
		if (g_flags.cycle_intervals_to_dump > -1)
			g_flags.cycle_intervals_to_dump = -25;
		else if (g_flags.cycle_intervals_to_dump > -1575)
			g_flags.cycle_intervals_to_dump -= 25;
		else
			g_flags.cycle_intervals_to_dump = -1600;
	}
}
