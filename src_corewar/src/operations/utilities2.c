/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/17 23:11:04 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	modify_carry(struct s_process *process, t_op_arg ret)
{
	if (ret == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

int		check_registors(uint8_t op_code, struct s_parameter *params)
{	
	uint8_t		i;

	i = 0;
	while (i < g_op_tab[op_code].argc)
	{
		if ((params[i].param_type == T_REG)
			&& (params[i].param_val.val > REG_NUMBER
			|| params[i].param_val.val <= 0))
			return (-1);
		i++;
	}
	return (0);
}