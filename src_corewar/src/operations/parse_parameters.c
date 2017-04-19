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


static void					memmove_arg(uint8_t *arena, uint8_t *src,
								uint8_t *dst, size_t size)
{
	size_t	i;

	if (dst > src)
	{
		i = 0;
		while (i)
		{
			*(dst + i) = *mask_ptr(arena, src + i);
			i++;
		}
	}
	else
	{
		while (size)
		{
			size--;
			*(dst + size) = *mask_ptr(arena, src + size);
		}
	}
}

static union u_val		get_param_value(uint8_t *arena, t_param_type type,
							uint8_t *arg)
{
	union u_val		val;

	memmove_arg(arena, arg, val.arr, sizeof_param(type));
	return (val);
}

/*
**	Itterate through parameter encoding byte, collect corresponding data into
**		parameters array
*/
int			parse_parameters(uint8_t *arena, struct s_process *process,
				struct s_parameter *params)
{
	uint8_t		parameter_encoding;
	uint8_t		i;
	uint8_t		*parameter_ptr;

	parameter_encoding = *(mask_ptr(arena, process->pc + 1));
	parameter_ptr = mask_ptr(arena, process->pc + 1);
	i = 0;
	while (i < g_op_tab[process->op_code].argc)
	{
		params[i].type = parameter_encoding >> (6 - (2 * i)) & 0x3;
		params[i].val = get_param_value(arena, params[i].type, parameter_ptr);
		parameter_ptr += sizeof_param(params[i].type);
		i++;
	}
	return (1);
}













