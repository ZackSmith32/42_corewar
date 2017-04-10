/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 10:39:43 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/09 13:21:01 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_memory.h"

/*
** Checks to see if dst is located before or after src. If dst is located
** after src the buffer is copied back to front, otherwise it is copied front
** to back.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*anchor;
	char	*csrc;

	anchor = (char *)dst;
	csrc = (char *)src;
	if (!src || !dst)
		return (NULL);
	if (dst > src)
		while (len-- > 0)
			anchor[len] = csrc[len];
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
