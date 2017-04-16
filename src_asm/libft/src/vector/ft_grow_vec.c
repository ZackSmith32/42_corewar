/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grow_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:26:09 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/15 16:43:32 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

/*
** If neccsary ft_grow_vec will double the amount of space allocated for a
** vecotr in order to accomadate the new size needed.
*/

int	ft_grow_vec(t_vec *self, size_t requested_bytes)
{
	size_t	byte_count;
	size_t	new_size;

	byte_count = self->total * self->size;
	if (requested_bytes > byte_count)
	{
		new_size = 2 * byte_count;
		new_size = (requested_bytes > new_size ? requested_bytes : new_size);
		if ((!(self->arr = ft_memreallocf(self->arr, new_size, byte_count))))
			return (0);
		self->total = new_size / self->size;
	}
	return (1);
}
