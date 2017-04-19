/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/05 13:46:56 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			move_one(struct s_game *game, struct s_process *process)
{
	move_pc(game->arena, &process->pc, 1);
	return (0);
}

void		move_pc(uint8_t *arena, uint8_t **pc, int move)
{
	*pc = mask_ptr(arena, *pc + move);
}

uint8_t		*mask_ptr(uint8_t *arena, uint8_t *ptr)
{
	ptr = ((ptr - arena) % MEM_SIZE) + arena;
	if (ptr > arena + MEM_SIZE)
		ptr -= MEM_SIZE;
	else if (ptr < arena)
		ptr += MEM_SIZE;
	return(ptr);
}

size_t						sizeof_param(enum e_param_type param_type)
{
	if (param_type == REG)
		return (REG_SIZE);
	if (param_type == DIR)
		return (DIR_SIZE);
	if (param_type == IND)
		return (IND_SIZE);
	return (NO_PARAM);
}
size_t					calc_offset(struct s_parameter *params, int argc)
{
	size_t	size;

	size = 2;
	while (argc)
	{
		argc--;
		size += sizeof_param(params[argc].type);
	}
	return (size);
}

/*
**	returns a copy of input with reversed bytes

uint8_t		*reverse_bytes(uint8_t *arena, uint8_t *ptr, size_t size)
{
	uint8_t		temp[sizeof(op_arg_t)];
	uint8_t		i;

	ft_memmove_core(arena, ptr, temp, size);
	i = 0;
	while (size > 0)
	{
		size--;
		temp[i] = *mask_ptr(arena, ptr, size);
		i++;
	}
	return (temp);
}
*/
