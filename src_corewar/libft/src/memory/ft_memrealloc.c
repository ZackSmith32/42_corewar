/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:41:05 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 10:04:03 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memory.h"

/*
** Allocates a new space of memory for ptr, and copies as much memory as
** possible from the original ptr to the new one.
*/

void	*ft_memrealloc(void *ptr, size_t new_size)
{
	void	*newbuf;

	if (!(newbuf = ft_memalloc(new_size)))
		return (NULL);
	if (!ptr)
		return (newbuf);
	ft_memmove(newbuf, ptr, new_size);
	ft_memdel(&ptr);
	return (newbuf);
}
