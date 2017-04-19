/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/03/04 18:52:04 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		print_process(uint8_t *arena, struct s_process *process)
{
	size_t	i;

	ft_printf("  carry: %d", (int)process->carry);
	ft_printf("  pc: %4zu", (size_t)(process->pc - arena));
	ft_printf("  countdown: %04u", process->countdown);
	ft_printf("  op_code: %02u", process->op_code);
	ft_printf("  called_live: %03u", process->called_live);
	i = 0;
	while (i < REG_NUMBER)
	{
		ft_printf("  r%zu: %hx", i, process->registors[i]);
		i++;
	}
}

void		print_processes(uint8_t *arena, t_list *processes)
{
	size_t	i;

	i = 0;
	while (processes)
	{
		ft_printf("\n\033[1mprocess %03zu\033[0m", i);
		print_process(arena, processes->content);
		processes = processes->next;
		i++;
	}
}

int				game_print(struct s_game *game)
{
	if (g_flags.list & FLAG_P || g_flags.list & FLAG_V)
	{
		write(1, "\033c", 2);
		if (g_flags.list & FLAG_P)
			print_hex(game->arena, MEM_SIZE, game->processes);
		if (g_flags.list & FLAG_V)
		{
			ft_putchar('\n');
			print_processes(game->arena, game->processes);
			ft_putchar('\n');
			ft_printf("current_cycles: %u\n", game->current_cycles);
		}
		sleep(1);
	}
	return (0);
}