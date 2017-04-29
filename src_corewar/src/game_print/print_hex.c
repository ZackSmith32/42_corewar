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

uint32_t		color_code(t_list *process)
{
	return (((struct s_process *)process->content)->champ_index
		% (COLORS - 10) + 10);
}

static int		hex_color(t_list *processes, uint8_t *loc_conv,
					uint8_t *writer_loc_conv)
{
	t_list		*node;
	uint32_t	cnum;

	node = processes;
	while (node && ((struct s_process *)node->content)->pc != loc_conv)
		node = node->next;
	if (node)
		cnum = color_code(node);
	else
		cnum = -(*writer_loc_conv % (COLORS - 9) + 9);
	return ((node || *writer_loc_conv) ? cnum : -1);
}

static void		print_byte_in_hex(uint8_t byte, int color_code)
{
	uint8_t	c;

	c = 0x0F & byte;
	byte = 0x0F & (byte >> 4);
	byte = byte > 9 ? byte - 10 + 'A' : byte + '0';
	c = c > 9 ? c - 10 + 'A' : c + '0';
	if (color_code > 9)
		attrset(COLOR_PAIR(color_code) | A_BLINK);
	else if (color_code < -9)
		attrset(COLOR_PAIR(-color_code) | A_REVERSE);
	else if (byte != '0' || c != '0')
		attrset(COLOR_PAIR(3));
	else
		attrset(COLOR_PAIR(2) | A_NORMAL);
	printw("%c%c", byte, c);
	attrset(COLOR_PAIR(2) | A_NORMAL);
	printw(" ");
}

void			print_hex(void *loc, void *writer_loc, size_t size,
					t_list *processes)
{
	uint8_t		*loc_conv;
	uint8_t		*writer_loc_conv;

	loc_conv = (uint8_t*)loc;
	writer_loc_conv = (uint8_t*)writer_loc;
	while (size)
	{
		if (0 == size % 64)
		{
			attron(COLOR_PAIR(1));
			printw("  \n  ");
			attron(COLOR_PAIR(2));
			printw(" ");
		}
		print_byte_in_hex(*loc_conv,
			hex_color(processes, loc_conv, writer_loc_conv));
		loc_conv++;
		writer_loc_conv++;
		size--;
	}
	attron(COLOR_PAIR(1));
	printw("  \n%197c", ' ');
	attron(COLOR_PAIR(2));
}

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
