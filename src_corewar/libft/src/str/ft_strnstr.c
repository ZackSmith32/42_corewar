/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:16:06 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/29 12:55:22 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Searches for a substring in a string. Searches up to len characters for the
** end of the substring.
*/

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	const char	*li_anchor;
	const char	*big_anchor;
	size_t		len_anchor;

	if (!*l)
		return ((char *)b);
	li_anchor = l;
	while (*b && len-- > 0)
	{
		big_anchor = b;
		l = li_anchor;
		len_anchor = len + 1;
		if (*b == *l)
		{
			while (*b++ == *l++ && len_anchor-- != 0)
				if (!(*l))
					return ((char *)big_anchor);
			if (len_anchor == 4294967295)
				return (NULL);
		}
		b = big_anchor + 1;
	}
	return (NULL);
}
