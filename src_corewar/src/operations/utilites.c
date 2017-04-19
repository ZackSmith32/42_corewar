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
	move = move % MEM_SIZE;
	*pc += move;
	if (*pc < arena)
		*pc += MEM_SIZE;
	else if (*pc > arena + MEM_SIZE)
		*pc -= MEM_SIZE;
}

uint8_t		*mask_pc(uint8_t *ptr, size_t offset)
{
	uint8_t		*wrap;

	offset = offset % MEM_SIZE;
	if (ptr - g_first_mem_slot + offset < MEM_SIZE)
		return (ptr + offset);
	wrap = ((ptr + offset) - g_first_mem_slot) % MEM_SIZE;
	return (g_first_mem_slot + wrap);
}

uint8_t		*ft_memmove_core(uint8_t *arena, uint8_t *src,
													uint8_t *dst, size_t size)
{
	size_t	i;

	if (dst > src)
	{
		i = 0;
		while (i)
		{
			*mask_pc(dst, arena, i) = *mask_pc(src, arena, i);
			i++;
		}
	}
	else
	{
		while (size)
		{
			size--;
			*mask_pc(dst, arena, size) = *mask_pc(src, arena, size);
		}
	}
}
/*
**	returns a copy of input with reversed bytes
*/
uint8_t		*reverse_bytes(uint8_t *ptr, size_t size)
{
	uint8_t		temp[sizeof(op_arg_t)];
	uint8_t		i;

	ft_memmove_core(ptr, temp, size);
	i = 0;
	while (size > 0)
	{
		size--;
		temp[i] = mask_pc(ptr, size);
		i++;
	}
	return (temp);
}
