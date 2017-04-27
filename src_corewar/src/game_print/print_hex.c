/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/05 13:44:18 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void			*memxor(void *p, int val, size_t size)
{
	unsigned char *pb;

	pb = p;
	while (size-- > 0)
		*pb++ ^= (unsigned char)val;
	return (p);
}

uint32_t		color_code(t_list *process)
{
	uint32_t	cnum;

	cnum = ((struct s_process *)process->content)->registors[0];
	memxor(&cnum, ~0, sizeof(cnum));
	if (cnum > MAX_PLAYERS)
		return (1);
	cnum = cnum % (COLORS - 10) + 10;
	return (cnum);
}

static int		hex_color(t_list *processes, uint8_t *loc_conv)
{
	t_list		*node;
	uint32_t	cnum;

	node = processes;
	while (node && ((struct s_process *)node->content)->pc != loc_conv)
		node = node->next;
	if (node)
		cnum = color_code(node);
	return ((node) ? cnum : -1);
}

static void		print_byte_in_hex(uint8_t byte, int color_code)
{
	uint8_t	c;

	c = 0x0F & byte;
	byte = 0x0F & (byte >> 4);
	byte = byte > 9 ? byte - 10 + 'A' : byte + '0';
	c = c > 9 ? c - 10 + 'A' : c + '0';
	if (color_code != -1)
		attron(COLOR_PAIR(color_code) | A_DIM);
	else if (byte != '0' || c != '0')
		attron(COLOR_PAIR(3));
	else
		attrset(COLOR_PAIR(2) | A_NORMAL);
	printw("%c%c", byte, c);
	attrset(COLOR_PAIR(2) | A_NORMAL);
	printw(" ");
}

void			print_hex(void *loc, size_t size,
					t_list *processes)
{
	uint8_t		*loc_conv;

	attron(COLOR_PAIR(1));
	printw("   %s%-10d%20s%-155d", "speed: ", 1000000 - g_flags.wait_time,
		"skip: ", g_flags.cycle_intervals_to_dump);
	loc_conv = (uint8_t*)loc;
	while (size)
	{
		if (0 == size % 64)
		{
			attron(COLOR_PAIR(1));
			printw("  \n  ");
			attron(COLOR_PAIR(2));
			printw(" ");
		}
		print_byte_in_hex(*loc_conv, hex_color(processes, loc_conv));
		loc_conv++;
		size--;
	}
	attron(COLOR_PAIR(1));
	printw("  \n%197c", ' ');
	attron(COLOR_PAIR(2));
}
