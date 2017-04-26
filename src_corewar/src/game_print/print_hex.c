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

static void *memxor(void *p, int val, size_t size)
{
	unsigned char *pb;

	pb = p;
	while (size-- > 0)
		*pb++ ^= (unsigned char)val;
	return p;
}

static void		print_byte_in_hex(t_strvec *out, uint8_t byte, int pc_num)
{
	uint8_t	c;

	(void)out;
	c = 0x0F & byte;
	byte = 0x0F & (byte >> 4);
	byte = byte > 9 ? byte - 10 + 'A' : byte + '0';
	c = c > 9 ? c - 10 + 'A' : c + '0';
	//ft_jasprintf(out, "\033[0m");
//	attron(A_STANDOUT | COLOR_PAIR(0));
	if (pc_num != -1)
	{
		//ft_jasprintf(out, "\033[%u;7m", pc_num % 7 + 31);
		attron(COLOR_PAIR(pc_num % 7 + 10) | A_DIM);
	}
	else if (byte != '0' || c != '0')
	{
		//ft_jasprintf(out, "\033[96m");
		attron(COLOR_PAIR(3));
	}
	//ft_jasprintf(out, "%c%c", byte, c);
	//ft_jasprintf(out, "\033[0m");
	//ft_jasprintf(out, " ");
	printw("%c%c", byte, c);
	attrset(COLOR_PAIR(2) | A_NORMAL);
	printw(" ");
}

void			print_hex(t_strvec *out, void *loc, size_t size,
					t_list *processes)
{
	uint8_t		*loc_conv;
	t_list		*node;
	uint32_t	cnum;

	(void)out;
	//ft_jasprintf(out, "\033[100m%196\033[0m");
	attron(COLOR_PAIR(1));
	printw("%195c", ' ');
	loc_conv = (uint8_t*)loc;
	while (size)
	{
		if (0 == size % 64)
		{
			//ft_jasprintf(out, "\033[100m  \n  \033[0m ");
			attron(COLOR_PAIR(1));
			printw("  \n  ");
			attron(COLOR_PAIR(2));
			printw(" ");
			
		}
		node = processes;
		while (node && ((struct s_process *)node->content)->pc != loc_conv)
			node = node->next;
		if (!(cnum = 0) && node)
		{
			cnum = ((struct s_process *)node->content)->registors[0];
			memxor(&cnum, ~0, sizeof(cnum));
		}
		print_byte_in_hex(out, *loc_conv, (node) ? cnum : -1);
		loc_conv++;
		size--;
	}
	//ft_jasprintf(out, "\033[100m  \n%198\033[0m");
	attron(COLOR_PAIR(1));
	printw("  \n%197c", ' ');
	attron(COLOR_PAIR(2));
}
