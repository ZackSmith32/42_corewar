/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:01:25 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/17 17:51:38 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	read_vm(uint8_t *ptr, size_t size, uint8_t *ret)
{
	size_t	end;
	size_t	start;

	end = size;
	start = 0;
	while (end > 0)
	{
		end--;
		ret[start] = ptr[end];
		start++;
	}
}

void		get_param_value(uint8_t parameter_type, uint8_t *ptr,
				struct s_parameter *parameter, uint8_t *byte_index)
{
	uint8_t			ind_offset[IND_SIZE];

	if ((parameter_type & 0xc0) == 0x40)
	{
		read_vm(ptr + *byte_index, 1, parameter->param_val.arr);
		parameter->param_type = T_REG;
		*byte_index += REG_SIZE;
	}
	else if ((parameter_type & 0xc0) == 0x80)
	{
		read_vm(ptr + *byte_index, DIR_SIZE, parameter->param_val.arr);
		parameter->param_type = T_DIR;
		*byte_index += REG_SIZE;
	}
	else if ((parameter_type & 0xc0) == 0xc0)
	{
		read_vm(ptr + *byte_index, IND_SIZE, ind_offset);
		read_vm(ptr + *(uint16_t *)ind_offset, REG_SIZE, parameter->param_val.arr);
		parameter->param_type = T_IND;
		*byte_index += REG_SIZE;
	}
}

/*
**	Itterate through parameter encoding byte, collect corresponding data into
**		parameters array
*/
int			parse_parameters(struct s_process *process,
				struct s_parameter *params)
{
	uint8_t		parameter_encoding;
	uint8_t		byte_index;
	uint8_t		parameter_index;

	parameter_encoding = *(process->pc + 1);
	byte_index = 2;
	parameter_index = 0;
	while (parameter_index < g_op_tab[process->op_code].argc)
	{
		get_param_value(parameter_encoding, process->pc,
			&(params[parameter_index]), &byte_index);
		parameter_encoding = parameter_encoding << 2;
		parameter_index++;
	}
	return (1);
}













