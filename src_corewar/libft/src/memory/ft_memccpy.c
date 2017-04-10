/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 09:01:39 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 09:11:42 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Copies a string of bytes from src to dst, if character c occurs it stops
** copying and returns a pointer to the next character.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tail;
	char			*srctail;

	tail = (unsigned char *)dst;
	srctail = (char *)src;
	while (n-- > 0)
	{
		*tail++ = *srctail++;
		if (*(tail - 1) == (unsigned char)c)
			return ((void *)tail);
	}
	return (NULL);
}
