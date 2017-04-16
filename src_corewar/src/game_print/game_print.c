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

	ft_printf("   carry: %d\n", (int)process->carry);
	ft_printf("   pc: %zu\n", (size_t)(process->pc - (void*)arena));
	ft_printf("   countdown: %u\n", process->countdown);
	ft_printf("   op_code: %u\n", process->op_code);
	i = 0;
	while (i < REG_NUMBER)
	{
		ft_printf("   r%zu: %hx\n", i, process->registors[i]);
		i++;
	}
}

void		print_processes(uint8_t *arena, t_list *processes)
{
	size_t	i;

	i = 0;
	while (processes)
	{
		ft_putchar('\n');
		ft_printf("\033[1mprocess %zu\033[0m\n", i);
		print_process(arena, processes->content);
		processes = processes->next;
		i++;
	}

}

int				game_print(struct s_game *game)
{
	print_hex(game->arena, MEM_SIZE);
	ft_putchar('\n');
	print_processes(game->arena, game->processes);
	return (0);
}