/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvgrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:16:24 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/07 16:18:38 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

/*
** ft_strvgrow will grow the space allocated in the strvec by twice doubling
** the requested size.
*/

size_t	ft_strvgrow(t_strvec *self, size_t index)
{
	size_t	new_size;

	if (index > self->size)
	{
		new_size = (index > (2 * self->size) ? index : (2 * self->size));
		if (!(self->str = ft_memreallocf(self->str, new_size, self->size)))
			return ((size_t)-1);
		return (new_size);
	}
	return (self->size);
}
