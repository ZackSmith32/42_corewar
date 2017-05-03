/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2017/05/02 20:24:40 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/*
** overflows likely broken because of bad parameter size
*/

int					add(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[4].argc];

	if (-1 == parse_and_validate_parameters(game, process, params))0
		return (0);
	if (--params[0].param_val.val >= REG_NUMBER
		|| --params[1].param_val.val >= REG_NUMBER
		|| --params[2].param_val.val >= REG_NUMBER)
		return (0);
	params[0].param_val.val = process->registors[params[0].param_val.val];
	params[1].param_val.val = process->registors[params[1].param_val.val];
	change_end(params[0].param_val.arr, REG_SIZE);
	change_end(params[1].param_val.arr, REG_SIZE);
	process->registors[params[2].param_val.val] = (
		params[0].param_val.val + params[1].param_val.val);
	change_end(process->registors + params[2].param_val.val, REG_SIZE);
	process->carry = process->registors[params[2].param_val.val] == 0;
	return (0);
}

int					sub(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[5].argc];

	if (-1 == parse_and_validate_parameters(game, process, params))0
		return (0);
	if (--params[0].param_val.val >= REG_NUMBER
		|| --params[1].param_val.val >= REG_NUMBER
		|| --params[2].param_val.val >= REG_NUMBER)
		return (0);
	params[0].param_val.val = process->registors[params[0].param_val.val];
	params[1].param_val.val = process->registors[params[1].param_val.val];
	change_end(params[0].param_val.arr, REG_SIZE);
	change_end(params[1].param_val.arr, REG_SIZE);
	process->registors[params[2].param_val.val] = (
		params[0].param_val.val - params[1].param_val.val);
	change_end(process->registors + params[2].param_val.val, REG_SIZE);
	process->carry = process->registors[params[2].param_val.val] == 0;
	return (0);
}
