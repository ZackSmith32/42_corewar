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

void				set_parameter(uint8_t *arena, uint8_t **pc_temp, 
						struct s_parameter *parameter, uint8_t size)
{
	read_arena(arena, *pc_temp, (*parameter).param_val.arr, size);
	*pc_temp = mask_ptr(read_arena, *pc_temp += size);
}

struct s_parameter	get_param_value(struct s_game *game, 
						struct s_process *process, uint8_t parameter_type,
						uint8_t **pc_temp)
{
	struct s_parameter		parameter;

	ft_bzero(&parameter, sizeof(struct s_parameter));
	if (parameter_type == REG_CODE)
	{
		set_parameter(game->arena, pc_temp, &parameter, 1);
		parameter.param_type = T_REG;
	}
	else if (parameter_type == DIR_CODE)
	{
		if (g_op_tab[process->op_code].dir_as_ind)
			set_parameter(game->arena, pc_temp, &parameter, IND_SIZE);
		else
			set_parameter(game->arena, pc_temp, &parameter, REG_SIZE);
		parameter.param_type = T_DIR;
	}
	else if (parameter_type == IND_CODE)
	{
		set_parameter(game->arena, pc_temp, &parameter, IND_SIZE);
		parameter.param_type = T_IND;
	}
	return (parameter);
}

/*
**	Itterate through parameter encoding byte, collect corresponding data into
**		parameters array
*/
int			parse_parameters(struct s_game *game, struct s_process *process, 
				struct s_parameter *params, uint8_t **pc_temp)
{
	uint8_t		parameter_encoding;
	uint8_t		parameter_index;

	parameter_encoding = *(mask_ptr(game->arena, *pc_temp + 1));
	*pc_temp = mask_ptr(game->arena, *pc_temp + 2);
	parameter_index = 0;
	while (parameter_index < g_op_tab[process->op_code].argc)
	{
		params[parameter_index] = 
			get_param_value(game, process, parameter_encoding, pc_temp);
		parameter_encoding = parameter_encoding << 2;
		parameter_index++;
	}
	return (1);
}













