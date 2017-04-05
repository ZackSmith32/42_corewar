/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 09:08:53 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/05 10:57:29 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>


/*
**	use op code to get function pointer out of global op array
*/
int			op_lookup(int op_to_execute_code, void *op_pointer)
{
	unsigned int	i;

	i = 0;
	while (i < 17)
	{
		if (g_op_tab[i].op_code == op_to_execute)
		{
			op_pointer = g_op_tab.function_pointer;
			return ()
		}
		i++;
	}
	return (-1);
}

