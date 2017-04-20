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

static void		print_byte_in_hex(t_strvec *out, uint8_t byte, int pc_num)
{
	uint8_t	c;

	c = 0x0F & byte;
	byte = 0x0F & (byte >> 4);
	byte = byte > 9 ? byte - 10 + 'A' : byte + '0';
	c = c > 9 ? c - 10 + 'A' : c + '0';
	ft_jasprintf(out, "\033[0m");
	if (pc_num != -1)
		ft_jasprintf(out, "\033[%u;7m", pc_num % 7 + 31);
	else if (byte != '0' || c != '0')
		ft_jasprintf(out, "\033[96m");
	ft_jasprintf(out, "%c%c\033[0m ", byte, c);
}

void			print_hex(t_strvec *out, void *loc, size_t size,
					t_list *processes)
{
	uint8_t	*loc_conv;
	t_list	*node;
	int		i;

	ft_jasprintf(out, "\033[100m%196\033[0m");
	loc_conv = (uint8_t*)loc;
	while (size && !(i = 0))
	{
		if (0 == size % 64)
			ft_jasprintf(out, "\033[100m  \n  \033[0m ");
		node = processes;
		while (node
				&& ((struct s_process *)node->content)->pc != loc_conv && ++i)
			node = node->next;
		print_byte_in_hex(out, *loc_conv, (node) ? i : -1);
		loc_conv++;
		size--;
	}
	ft_jasprintf(out, "\033[100m  \n%198\033[0m");
}
