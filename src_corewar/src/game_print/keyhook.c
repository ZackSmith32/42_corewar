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

void	key_pause(char key)
{
	_Bool	pause;

	pause = (key == ' ') ? 1 : 0;
	while (pause)
		if (getch() == ' ')
			pause = 0;
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