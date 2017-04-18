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

static void		print_byte_in_hex(uint8_t byte)
{
	uint8_t	c;

	c = 0x0F & byte;
	byte = 0x0F & (byte >> 4);
	byte = byte > 9 ? byte - 10 + 'A': byte + '0';
	c = c > 9 ? c - 10 + 'A' : c + '0';
	if (byte != '0' || c != '0')
		write(1, "\033[36m", 5);
	write(1, &byte, 1);
	write(1, &c, 1);
	if (byte != '0' || c != '0')
		write(1, "\033[0m", 4);
}

void		print_hex(void *loc, size_t size, t_list *processes)
{
	uint8_t	*loc_conv;
	t_list	*node;

	loc_conv = (uint8_t*)loc;
	while (size)
	{
		node = processes;
		while (node && ((struct s_process *)node->content)->pc != loc_conv)
			node = node->next;
		if (node)
			write(1, "\033[7m", 4);
		print_byte_in_hex(*loc_conv);
		if (node)
			write(1, "\033[0m", 4);
		ft_putchar(' ');
		loc_conv++;
		size--;
	}
}