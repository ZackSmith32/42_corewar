/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 18:30:19 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 10:02:43 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_memory.h"

/*
** Allocates a fresh 'size' chunk in memory with each byte allocated to 0.
*/

void	*ft_memalloc(size_t size)
{
	void *memory;

	if (!(memory = (void *)malloc(size)))
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
