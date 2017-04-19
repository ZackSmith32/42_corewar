/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:01:25 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/17 18:20:35 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/*
**	TODO : make sure to accound for functions taht wrap around memory
**		 : change read_vm to ft_memmove_core
*/
struct s_parameter	get_param_value(struct s_game *game, uint8_t parameter_type,
				struct s_process process, uint8_t *byte_offset)
{
	struct s_parameter		parameter;

	if (parameter_type == REG_CODE)
	{
		read_arena(game->arena, process->pc, parameter.param_val.arr, 1);
		parameter.param_type = T_REG;
		*byte_offset += 1;
	}
	else if (parameter_type == DIR_CODE)
	{
		if (g_op_tab[process->op_code].dir_as_ind)
			read_arena(game->arena, process->pc, parameter.param_val.arr, IND_SIZE);
		else
			read_arena(game->arena, process->pc, parameter.param_val.arr, REG_SIZE);
		parameter.param_type = T_DIR;
		*byte_offset += REG_SIZE;
	}
	else (parameter_type == IND_CODE)
	{
		read_arena(game->arena, process->pc, parameter.param_val.arr, IND_SIZE);
		parameter.param_type = T_IND;
		*byte_offset += IND_SIZE;
	}
	return (parameter);
}

/*
**	Itterate through parameter encoding byte, collect corresponding data into
**		parameters array
*/
int			parse_parameters(struct s_game *game, struct s_process *process,
				struct s_parameter *params, uint8_t *byte_offset)
{
	uint8_t		parameter_encoding;
	uint8_t		parameter_index;

	parameter_encoding = *(mask_ptr(game->arena, process->pc + 1));
	*byte_offset = 2;
	parameter_index = 0;
	while (parameter_index < g_op_tab[process->op_code].argc)
	{
		params[parameter_index] = get_param_value(game, parameter_encoding, process, byte_offset);
		parameter_encoding = parameter_encoding << 2;
		parameter_index++;
	}
	return (1);
}













