/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecapp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:39:49 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/17 14:40:31 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

/*
** ft_vecapp is meant to be a safe way to append an array to the end of
** a vector of the same type. It will return an error if it is unable to
** allocate the neccsary amount of memory for the concatenation.
**
** Parameters:
**	t_vex *self: the vector which will be appended to.
**	void *src: The array that will be appended to the vector.
**	size_t n: The number of bytes to be appended from the source array.
**
** Return:
**	0 = Failure
**	1 = Success
*/

int	ft_vecapp(t_vec *self, void *src, size_t n)
{
	size_t	offset;

	offset = self->len * self->size;
	if (n % self->size || !(ft_grow_vec(self, n + offset)))
		return (0);
	ft_memmove(self->arr + offset, src, n);
	self->len += (n / self->size);
	return (1);
}
