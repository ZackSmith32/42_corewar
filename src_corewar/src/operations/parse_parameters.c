/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:01:25 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/15 22:28:49 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>


void		get_param_value(
				uint8_t parameter_type, 
				uint8_t *ptr, 
				union u_parameter *parameter,
				uint8_t *byte_index 
				)
{
	uint8_t			ret[4];
	uint8_t			ind_offset[IND_SIZE];

	if ((parameter_type & 0xc0) == 0x40)
	{
		read_vm(ptr + *byte_index, 1, parameter->val);
	}
	else if ((parameter_type & 0xc0) == 0x80)
	{
		read_vm(ptr + *byte_index, DIR_SIZE, parameter->val);
	}
	else if ((parameter_type & 0xc0) == 0xc0)
	{
		read_vm(ptr + *byte_index, IND_SIZE, ind_offset);
		read_vm(ptr + *(uint16_t *)ind_offset, REG_SIZE,  parameter->val);
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

void		parse_parameters(struct s_process *process, 
				union u_parameter *parameters)
{
	uint8_t		parameter_encoding;
	uint8_t		byte_index;
	uint8_t		*pc;
	uint8_t		parameter_index;

	pc = process->pc;
	parameter_encoding = (uint8_t)(*(process->pc + 1));
	byte_index = 2;
	parameter_index = 0;
	while ((parameter_encoding & 0xff) != 0)
	{
		get_param_value(parameter_encoding, pc, &(parameters[parameter_index]), &byte_index);

		if ((parameter_encoding & 0xc0) == 0x40)
			byte_index += 1;
		else if ((parameter_encoding & 0xc0) == 0x80)
			byte_index += DIR_SIZE;
		else if ((parameter_encoding & 0xc0) == 0xc0)
			byte_index += IND_SIZE;
		parameter_encoding = parameter_encoding << 2;
		parameter_index++;
	}
	
}


/*
**	still wondering if we have to defend against if the memory doesn't fit
**	the correct pattern for the operation
*/













