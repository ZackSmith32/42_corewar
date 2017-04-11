/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:55:39 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 10:17:36 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Searches a string and returns the last instance of character 'c'.
*/

char	*ft_strrchr(const char *str, int c)
{
	char	*result;
	char	*tail;

	result = NULL;
	tail = (char *)str;
	while (*tail)
		if (*tail++ == c)
			result = tail - 1;
	if (*tail == c)
		return (tail);
	return (result);
}
