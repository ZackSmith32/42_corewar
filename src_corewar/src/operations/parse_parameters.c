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
void		get_param_value(struct s_game *game, uint8_t parameter_type,
				uint8_t *ptr, uint8_t *byte_offset)
{
	s_parameter		*parameter;

	parameter_type = (parameter_type & 0xc0) >> 6;
	if (parameter_type == REG_CODE)
	{
		ft_memove_core(game, mask_pc(ptr, *byte_offset), 1, parameter->param_val.arr);
		parameter->param_type = T_REG;
		*byte_offset += REG_SIZE;
	}
	else if (parameter_type == DIR_CODE)
	{
		ft_memove_core(game, mask_pc(ptr, *byte_offset), DIR_SIZE, parameter->param_val.arr);
		parameter->param_type = T_DIR;
		*byte_offset += REG_SIZE;
	}
	else if (parameter_type == IND_CODE)
	{
		ft_memove_core(game, mask_pc(ptr, *byte_offset), IND_SIZE, parameter->param_val.arr);
		// read_vm(ptr + *(op_arg_t *)ind_offset, REG_SIZE, parameter->param_val.arr);
		parameter->param_type = T_IND;
		*byte_offset += REG_SIZE;
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
	s_process	

	parameter_encoding = *(mask_pc(process->pc, 1));
	*byte_offset = 2;
	parameter_index = 0;
	while (parameter_index < g_op_tab[process->op_code].argc)
	{
		ft_memmove(&params[parameter_index], get_param_value(game, 
			parameter_encoding, process->pc, byte_offset));
		parameter_encoding = parameter_encoding << 2;
		parameter_index++;
	}
	return (1);
}













