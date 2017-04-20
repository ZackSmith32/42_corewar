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

void		reverse_bytes(uint8_t *ptr, size_t size, uint8_t *dest)
{
	uint8_t		i;

	i = 0;
	while (size > 0)
	{
		size--;
		dest[i] = ptr[size];
		i++;
	}
}

uint8_t		*read_arena(uint8_t *arena, uint8_t *arena_ptr, uint8_t *norm_ptr, size_t size)
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

uint8_t		*write_arena(uint8_t *arena, uint8_t *arena_ptr, uint8_t *norm_ptr, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		*mask_ptr(arena, &arena_ptr[i]) = norm_ptr[i];
	}
	return (arena_ptr);
}



























