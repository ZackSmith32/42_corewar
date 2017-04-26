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

	(void)out;
	printw("  carry: %d", (int)process->carry);
	printw("  pc: %4zu", (size_t)(process->pc - arena));
	printw("  countdown: %04u", process->countdown);
	printw("  op: %-6s", g_op_tab[process->op_code].name_short);
	printw("  called_live: %u", process->called_live);
	i = 0;
	if (g_flags.verbosity_level & V_REGISTORS)
		while (i < REG_NUMBER)
		{
			ft_bzero(&reg, sizeof(reg));
			reverse_bytes((uint8_t *)&process->registors[i], REG_SIZE, reg.arr);
			if (reg.val)
				attron(COLOR_PAIR(3));
			printw("  r%02zu: %010u", i + 1, reg.val);
			if (reg.val)
				attrset(A_NORMAL);
			i++;
		}
}

void		print_processes(t_strvec *out, uint8_t *arena, t_list *processes)
{
	size_t	i;

	(void)out;
	if (!(g_flags.verbosity_level & V_PROCESS))
		return ;
	i = 0;
	while (processes)
	{
		printw("\n");
		attron(COLOR_PAIR(color_code(processes)) | A_REVERSE);
		printw("process %03zu", i);
		attrset(A_NORMAL);
		print_process(out, arena, processes->content);
		processes = processes->next;
		i++;
	}
}
