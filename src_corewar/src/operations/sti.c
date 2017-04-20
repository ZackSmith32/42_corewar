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

int		sti(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[11].argc];
	uint8_t				*pc_temp;
	uint8_t				byte_offset;
	// uint64_t			number_to_store;

	byte_offset = 0;

	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	if (params[0].param_type == T_REG)
//		process->registors[params[0].param_val.val] = params[1].param_val.val
		;

	if (params[1].param_type == T_IND)
		;
	else if (params[1].param_type == T_DIR)
		;
	else if (params[1].param_type == T_REG)
		;

	if (params[2].param_type == T_DIR)
		;
	else if (params[2].param_type == T_REG)
		;
	return (0);
}













