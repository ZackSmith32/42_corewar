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

static int16_t	calc_sti_offset(struct s_process *process,
				struct s_parameter *params)
{
	union u_val	first;
	union u_val	second;

	first.val = 0;
	second.val = 0;
	if (params[1].param_type == T_REG)
		reverse_bytes((void *)&process->registors[params[0].param_val.val - 1], 
			REG_SIZE, first.arr);
	else
		reverse_bytes(params[1].param_val.arr, IND_SIZE, first.arr);
	if (params[2].param_type == T_REG)
		reverse_bytes((void *)&process->registors[params[1].param_val.val - 1], 
			REG_SIZE, second.arr);
	else
		reverse_bytes(params[2].param_val.arr, IND_SIZE, second.arr);
	return (first.val + second.val);
}

int		sti(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[11].argc];
	uint8_t				*pc_temp;
	ind_t				offset;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	if (-1 == check_registors(process->op_code, params)
			&& (process->pc = pc_temp))
		return (0);
	params[0].param_val.val = process->registors[params[0].param_val.val - 1];
	if (params[1].param_type == T_IND || params[1].param_type == T_DIR)
		change_end(params[1].param_val.arr, IND_SIZE);
	else if (params[1].param_type == T_REG)
			change_end((void *)&process->registors[params[1].param_val.val - 1], REG_SIZE);
	if (params[2].param_type == T_DIR)
		change_end(params[2].param_val.arr, IND_SIZE);
	else if (params[2].param_type == T_REG)
		temp_reg = process->registors[params[2].param_val.val - 1];
		change_end((void *)&temp_reg, REG_SIZE);
	write_arena(game->arena,
			process->pc + params[1].param_val.val + params[2].param_val.val,
			(uint8_t *)&params[0].param_val.val, REG_SIZE);
	process->pc = pc_temp;
	return (0);
}
