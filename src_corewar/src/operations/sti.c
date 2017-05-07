/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by aphan             #+#    #+#             */
/*   Updated: 2017/05/02 20:26:51 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int			flatten(uint8_t *arena, struct s_process *process,
						struct s_parameter *param, uint8_t *pc_og)
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
		param->param_val.val = ((t_s_op_arg)(t_ind)param->param_val.val)
			% IDX_MOD;
		read_arena(arena, pc_og + (t_s_op_arg)(t_ind)param->param_val.val,
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
	uint8_t				*pc_og;
	t_ind				offset;

	pc_og = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, params))
		return (0);
	if (--params[0].param_val.val >= REG_NUMBER
		|| -1 == flatten(game->arena, process, &params[1], pc_og)
		|| -1 == flatten(game->arena, process, &params[2], pc_og))
		return (0);
	offset = (t_s_op_arg)(params[1].param_val.val + params[2].param_val.val)
				% IDX_MOD;
	write_arena(game->arena, pc_og + offset,
		(uint8_t*)&process->registors[params[0].param_val.val], REG_SIZE);
	return (0);
}
