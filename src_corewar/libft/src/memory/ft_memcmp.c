/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:31:04 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/29 14:13:06 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Compares the bytes in two C strings of n length. Returns the difference of
** the first pair of differing bytes in the memory.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*st1 == *st2 && --n > 0)
	{
		st1++;
		st2++;
	}
	return ((int)(*st1 - *st2));
}
