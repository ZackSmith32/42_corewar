/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 09:08:53 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/05 09:30:43 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/*
**	use op code to get function pointer out of global op array
*/
void		instruction_lookup(int op_to_execute_code)
{
	unsigned int	i;

	i = 0;
	while (i < 17)
	{
		if (g_op_tab[i].op_code == op_to_execute)
			return (g_op_tab.function_pointer)
		i++;
	}
	return (-1);
}

void		instruction_executer(struct s_game *game, void *instruction)
{
	instruction(game);
}