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

void		print_process(t_strvec *out, uint8_t *arena,
				struct s_process *process)
{
	size_t		i;
	union u_val	reg;

	ft_jasprintf(out, "  carry: %d", (int)process->carry);
	ft_jasprintf(out, "  pc: %4zu", (size_t)(process->pc - arena));
	ft_jasprintf(out, "  countdown: %04u", process->countdown);
	ft_jasprintf(out, "  op: %-6s", g_op_tab[process->op_code].name_short);
	ft_jasprintf(out, "  called_live: %u", process->called_live);
	i = 0;
	while (i < REG_NUMBER)
	{
		if (i == 7)
			ft_jasprintf(out, "\n                         ");
		ft_bzero(reg.arr, 8);
		reverse_bytes((uint8_t *)&(process->registors[i]), REG_SIZE, reg.arr);
		ft_jasprintf(out, "  r%02zu: %010u", i + 1, (unsigned int)reg.val);
		i++;
	}
}

void		print_processes(t_strvec *out, uint8_t *arena, t_list *processes)
{
	size_t	i;

	if (!(g_flags.verbosity_level & V_PROCESS))
		return ;
	i = 0;
	while (processes)
	{
		ft_jasprintf(out, "\n\033[%um\033[1mprocess %03zu\033[0m",
			i % 7 + 31, i);
		print_process(out, arena, processes->content);
		processes = processes->next;
		i++;
	}
}