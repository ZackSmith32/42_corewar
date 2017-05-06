/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_lldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/05/03 16:27:06 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/*static t_ind	calc_ldi_offset(struct s_process *process,
				struct s_parameter *params)
{
	union u_val	first;

	first.val = 0;
	if (params[0].param_type == T_REG)
		reverse_bytes((void *)&process->registors[params[0].param_val.val - 1],
			REG_SIZE, first.arr);
	else
		reverse_bytes(params[0].param_val.arr, IND_SIZE, first.arr);
	if (params[1].param_type == T_REG)
		reverse_bytes((void *)&process->registors[params[1].param_val.val - 1],
			REG_SIZE, second.arr);
	else
		reverse_bytes(params[1].param_val.arr, IND_SIZE, second.arr);
	return (first.val + second.val);
}
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
		param->param_val.val %= IDX_MOD;
		read_arena(arena, pc_og + (t_ind)param->param_val.val,
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

int				ldi(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[0x0a].argc];
	uint8_t				*pc_og;
	t_ind				offset;

	pc_og = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, params))
		return (0);
	if (-1 == check_registors(process->op_code, params))
		return (0);
	offset = calc_ldi_offset(process, params);
	read_arena(game->arena, pc_og + (offset % IDX_MOD),
		(void *)&process->registors[params[2].param_val.val - 1], REG_SIZE);
	return (0);
}

int				lldi(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[0x0e].argc];
	uint8_t				*pc_og;
	t_ind				offset1;
	t_ind				offset2;

	pc_og = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, params))
		return (0);
	if (-1 == check_registors(process->op_code, params))
		return (0);
	offset1 = calc_ldi_offset(process, params);
	offset2 = offset1 + calc_ldi_offset(process, params);
	read_arena(game->arena, pc_og + offset,
		(void *)&process->registors[params[2].param_val.val - 1], REG_SIZE);
	modify_carry(process, process->registors[params[2].param_val.val - 1]);
	return (0);
}
*/