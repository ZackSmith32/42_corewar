/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2017/04/13 14:56:21 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int					add(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[4].argc];
	uint8_t				*pc_temp;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	process->pc = pc_temp;  //TODO: do we need to make pc_temp?
	if (params[0].param_val.val >= REG_NUMBER
		|| params[1].param_val.val >= REG_NUMBER
		|| params[2].param_val.val >= REG_NUMBER)
		return (0);
	params[0].param_val.val = process->registors[params[0].param_val.val];
	params[1].param_val.val = process->registors[params[1].param_val.val];
	change_end(params[0].param_val.arr, REG_SIZE);
	change_end(params[1].param_val.arr, REG_SIZE);
	process->registors[params[2].param_val.val] = (
		params[0].param_val.val + params[1].param_val.val);
	change_end(process->registors + params[2].param_val.val, REG_SIZE);
	if (process->registors[params[2].param_val.val] == 0)
		process->carry = 1;
	return (0);
}

int					sub(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[5].argc];
	uint8_t				*pc_temp;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	process->pc = pc_temp;
	if (params[0].param_val.val >= REG_NUMBER
		|| params[1].param_val.val >= REG_NUMBER
		|| params[2].param_val.val >= REG_NUMBER)
		return (0);
	params[0].param_val.val = process->registors[params[0].param_val.val];
	params[1].param_val.val = process->registors[params[1].param_val.val];
	change_end(params[0].param_val.arr, REG_SIZE);
	change_end(params[1].param_val.arr, REG_SIZE);
	process->registors[params[2].param_val.val] = (
		params[0].param_val.val - params[1].param_val.val);
	change_end(process->registors + params[2].param_val.val, REG_SIZE);
	if (process->registors[params[2].param_val.val] == 0)
		process->carry = 1;
	return (0);
}
