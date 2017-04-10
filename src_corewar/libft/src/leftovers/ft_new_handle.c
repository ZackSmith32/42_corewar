/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:44:49 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/06 18:06:32 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

/*
** Creates a blank handle with I rows and J columns. Use sizeof(type) for
** third parameter to give the number of bytes needed to allocate depending
** on the type of handle. (ie int would be 4, char 1, etc).
*/

void	**ft_new_handle(size_t i, size_t j, size_t type_size)
{
	void	**handle;
	size_t	index;

	if (!(handle = (void **)ft_memalloc(sizeof(void *) * i)))
		return (NULL);
	index = -1;
	while (++index < i)
		if (!(handle[index] = ft_memalloc(type_size * j)))
		{
			while (index-- > 0)
				ft_memdel(&handle[index]);
			ft_memdel(handle);
			return (NULL);
		}
	return (handle);
}
