/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:01:25 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/17 14:40:56 by zsmith           ###   ########.fr       */
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

void		get_param_value(
				uint8_t parameter_type, 
				uint8_t *ptr, 
				struct s_parameter *parameter,
				uint8_t *byte_index 
				)
{
	uint8_t			ret[4];
	uint8_t			ind_offset[IND_SIZE];

	if ((parameter_type & 0xc0) == 0x40)
	{
		read_vm(ptr + *byte_index, 1, parameter->val);
		parameter->parameter_type = REG_CODE;
	}
	else if ((parameter_type & 0xc0) == 0x80)
	{
		read_vm(ptr + *byte_index, DIR_SIZE, parameter->val);
		parameter->parameter_type = DIR_CODE;
	}
	else if ((parameter_type & 0xc0) == 0xc0)
	{
		read_vm(ptr + *byte_index, IND_SIZE, ind_offset);
		read_vm(ptr + *(uint16_t *)ind_offset, REG_SIZE,  parameter->val);
		parameter->parameter_type = IND_CODE
	}
}

/*
**	func   args   IND         DIR                   REG
**	0xff / 0xff / 0xff 0xff / 0xff 0xff 0xff 0xff / 0xff
*/

/*
**	parse_parameters:
**		> itterate through parameter list
**		> call get_param_value to populate array with params
*/

int			parse_parameters(struct s_process *process,
				struct s_parameter *parameters)
{
	uint8_t		parameter_encoding;
	uint8_t		byte_index;
	uint8_t		*pc;
	uint8_t		parameter_index;

	pc = process->pc;
	parameter_encoding = *(process->pc + 1);
	byte_index = 2;
	parameter_index = 0;
	if (parameter_encoding > 2)
		return (-1);
	while ((parameter_encoding & 0xff) != 0)
	{
		get_param_value(parameter_encoding, pc, &(parameters[parameter_index]), &byte_index)
		if ((parameter_encoding & 0xc0) == 0x40)
			byte_index += 1;
		else if ((parameter_encoding & 0xc0) == 0x80)
			byte_index += DIR_SIZE;
		else if ((parameter_encoding & 0xc0) == 0xc0)
			byte_index += IND_SIZE;
		parameter_encoding = parameter_encoding << 2;
		parameter_index++;
	}
	return (1);
}













