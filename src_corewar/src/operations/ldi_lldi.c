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

static t_ind	calc_ldi_offset(struct s_process *process,
				struct s_parameter *params)
{
	union u_val	first;
	union u_val	second;

	first.val = 0;
	second.val = 0;
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
	t_ind				offset;

	pc_og = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, params))
		return (0);
	if (-1 == check_registors(process->op_code, params))
		return (0);
	offset = calc_ldi_offset(process, params);
	read_arena(game->arena, pc_og + offset,
		(void *)&process->registors[params[2].param_val.val - 1], REG_SIZE);
	modify_carry(process, process->registors[params[2].param_val.val - 1]);
	return (0);
}
