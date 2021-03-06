/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/05/03 16:24:49 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		ld(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[0x02].argc];
	uint8_t				*pc_og;
	union u_val			ind_offset;

	pc_og = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, params))
		return (0);
	if (-1 == check_registors(process->op_code, params))
		return (0);
	if (params[0].param_type == T_DIR)
		process->registors[params[1].param_val.val - 1] =
			params[0].param_val.val;
	else if (params[0].param_type == T_IND)
	{
		reverse_bytes(params[0].param_val.arr, IND_SIZE, ind_offset.arr);
		read_arena(game->arena, pc_og + (((t_ind)ind_offset.val) % IDX_MOD),
				(uint8_t *)&process->registors[params[1].param_val.val - 1],
				REG_SIZE);
	}
	modify_carry(process, process->registors[params[1].param_val.val - 1]);
	return (0);
}

int		lld(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[0x0d].argc];
	uint8_t				*pc_og;
	union u_val			ind_offset;

	pc_og = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, params))
		return (0);
	if (-1 == check_registors(process->op_code, params))
		return (0);
	if (params[0].param_type == T_DIR)
		process->registors[params[1].param_val.val - 1] =
			params[0].param_val.val;
	else if (params[0].param_type == T_IND)
	{
		reverse_bytes(params[0].param_val.arr, IND_SIZE, ind_offset.arr);
		read_arena(game->arena, pc_og + (t_ind)ind_offset.val,
			(uint8_t *)&process->registors[params[1].param_val.val - 1],
			REG_SIZE);
	}
	modify_carry(process, process->registors[params[1].param_val.val - 1]);
	return (0);
}
