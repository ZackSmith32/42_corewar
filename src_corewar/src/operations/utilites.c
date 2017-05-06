/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/05/06 11:41:48 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

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
	return (ptr);
}

uint8_t		*read_arena(uint8_t *arena, uint8_t *arena_ptr,
				uint8_t *norm_ptr, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		norm_ptr[i] = *mask_ptr(arena, &arena_ptr[i]);
		i++;
	}
	return (norm_ptr);
}

uint8_t		*write_arena(uint8_t *arena, uint8_t *arena_ptr,
				uint8_t *norm_ptr, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		*mask_ptr(arena, &arena_ptr[i]) = norm_ptr[i];
		i++;
	}
	return (arena_ptr);
}
