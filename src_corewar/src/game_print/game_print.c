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

void		print_process(struct s_process *process)
{
	size_t	i;

	i = 0;
	while (i < REG_NUMBER)
	{
		ft_printf("r%zu: %hhx\n", i, process->registors[i]);
		i++;
	}
}

int				game_print(struct s_game *game)
{
	t_list	*link;
	size_t	i;

	print_hex(game->arena, MEM_SIZE);
	ft_putchar('\n');

	link = game->processes;
	i = 0;
	while (link)
	{
		ft_printf("process %zu\n", i);
		print_process(link->content);
		link = link->next;
		i++;
	}

	return (0);
}