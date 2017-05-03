/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2017/05/02 20:25:17 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/*
** todo: make int16_t a typedef that changes on IND_SIZE
*/

static int			flatten(uint8_t *arena, struct s_process *process,
						struct s_parameter *param)
{
	if (param->param_type == T_REG)
	{
		if (--param->param_val.val >= REG_NUMBER)
			return (-1);
		param->param_val.val = process->registors[param->param_val.val];
	}
	else if (param->param_type == T_IND)
	{
		change_end(param->param_val.arr, IND_SIZE);
		read_arena(arena, process->pc + ((t_ind)param->param_val.val % IDX_MOD),
			param->param_val.arr, DIR_SIZE);
	}
	return (0);
}

int					and(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[6].argc];
	uint8_t				*pc_temp;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
	{
		process->pc = pc_temp;
		return (-1);
	}
	process->pc = pc_temp;
	if (--params[2].param_val.val >= REG_NUMBER
		|| -1 == flatten(game->arena, process, &params[0])
		|| -1 == flatten(game->arena, process, &params[1]))
		return (0);
	process->registors[params[2].param_val.val] = (
		params[0].param_val.val & params[1].param_val.val);
	process->carry = process->registors[params[2].param_val.val] == 0;
	return (0);
}

int					or(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[7].argc];
	uint8_t				*pc_temp;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
	{
		process->pc = pc_temp;
		return (-1);
	}
	process->pc = pc_temp;
	if (--params[2].param_val.val >= REG_NUMBER
		|| -1 == flatten(game->arena, process, &params[0])
		|| -1 == flatten(game->arena, process, &params[1]))
		return (0);
	process->registors[params[2].param_val.val] = (
		params[0].param_val.val | params[1].param_val.val);
	process->carry = process->registors[params[2].param_val.val] == 0;
	return (0);
}

int					xor(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[8].argc];
	uint8_t				*pc_temp;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
	{
		process->pc = pc_temp;
		return (-1);
	}
	process->pc = pc_temp;
	if (--params[2].param_val.val >= REG_NUMBER
		|| -1 == flatten(game->arena, process, &params[0])
		|| -1 == flatten(game->arena, process, &params[1]))
		return (0);
	process->registors[params[2].param_val.val] = (
		params[0].param_val.val ^ params[1].param_val.val);
	process->carry = process->registors[params[2].param_val.val] == 0;
	return (0);
}
