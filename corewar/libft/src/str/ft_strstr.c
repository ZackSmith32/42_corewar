/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 21:15:28 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/28 11:03:07 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Searches for a substring within a string. Returns NULL if the substring
** is not present.
*/

char	*ft_strstr(const char *big, const char *little)
{
	const char	*li_anchor;
	const char	*big_anchor;

	if (!*little)
		return ((char *)big);
	li_anchor = little;
	while (*big)
	{
		big_anchor = big;
		little = li_anchor;
		if (*big == *little)
		{
			while (*big++ == *little++)
				if (!(*little))
					return ((char *)big_anchor);
		}
		big = big_anchor + 1;
	}
	return (NULL);
}
