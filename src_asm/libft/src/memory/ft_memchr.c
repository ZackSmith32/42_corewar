/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:03:50 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 12:37:10 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Locates the first occurence of c in string s.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tail;

	tail = (unsigned char *)s;
	while (n-- > 0)
		if (*tail++ == (unsigned char)c)
			return ((void *)(tail - 1));
	return (NULL);
}
