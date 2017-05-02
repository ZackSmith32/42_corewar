/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by aphan             #+#    #+#             */
/*   Updated: 2017/04/17 23:11:04 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
/*
static t_ind	calc_sti_offset(struct s_process *process,
				struct s_parameter *params)
{
	union u_val	first;
	union u_val	second;

	first.val = 0;
	second.val = 0;
	if (params[1].param_type == T_REG)
		reverse_bytes(
			(uint8_t*)&process->registors[(uint8_t)params[1].param_val.val - 1],
			REG_SIZE, first.arr);
	else
		reverse_bytes(params[1].param_val.arr, IND_SIZE, first.arr);
	if (params[2].param_type == T_REG)
		reverse_bytes((void *)&process->registors[params[2].param_val.val - 1],
			REG_SIZE, second.arr);
	else
		reverse_bytes(params[2].param_val.arr, IND_SIZE, second.arr);
	return (first.val + second.val);
}
*/

static int			flatten(uint8_t *arena, struct s_process *process,
						struct s_parameter *param)
{
	if (param->param_type == T_REG)
	{
		if (--param->param_val.val >= REG_NUMBER)
			return (-1);
		param->param_val.val = process->registors[param->param_val.val];
		change_end(param->param_val.arr, REG_SIZE);
		param->param_val.val = (t_s_op_arg)(t_s_reg)param->param_val.val;
	}
	else if (param->param_type == T_IND)
	{
		change_end(param->param_val.arr, IND_SIZE);
		param->param_val.val %= IDX_MOD;
		read_arena(arena, process->pc + (t_ind)param->param_val.val,
			param->param_val.arr, DIR_SIZE);
		change_end(param->param_val.arr, DIR_SIZE);
		param->param_val.val = (t_s_op_arg)(t_dir)param->param_val.val;
	}
	else if (param->param_type == T_DIR)
	{
		change_end(param->param_val.arr, IND_SIZE);
		param->param_val.val = (t_s_op_arg)(t_ind)param->param_val.val;
	}
	return (0);
}

int				sti(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[11].argc];
	uint8_t				*pc_temp;
	t_ind				offset;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	if (--params[0].param_val.val >= REG_NUMBER
		|| -1 == flatten(game->arena, process, &params[1])
		|| -1 == flatten(game->arena, process, &params[2]))
		return (0);
	offset = (t_s_op_arg)(params[1].param_val.val + params[2].param_val.val)
				% IDX_MOD;
	write_arena(game->arena, process->pc + offset,
		(uint8_t*)&process->registors[params[0].param_val.val], REG_SIZE);
	process->pc = pc_temp;
	return (0);
}
