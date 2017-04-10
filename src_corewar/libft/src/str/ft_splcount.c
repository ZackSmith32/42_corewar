/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 10:04:12 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/05 10:04:14 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Counts the number of memory chunks within range that are split by the
** character 'c'.
*/

unsigned int		ft_splcount(const void *v, char c, size_t len)
{
	unsigned int	word_count;
	char			*s;

	word_count = 0;
	s = (char *)v;
	if (!*s)
		return (0);
	while (len > 0)
	{
		while (*s++ == c && len > 0)
			len--;
		s--;
		while (*s++ != c && len > 0)
			len--;
		s--;
		word_count++;
	}
	if (*(s - 1) == c)
		word_count--;
	return (word_count);
}
