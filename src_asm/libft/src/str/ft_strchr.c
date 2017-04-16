/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:06:17 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 09:53:28 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Returns the position of the charcter 'c' located in the string.
*/

char	*ft_strchr(const char *str, int c)
{
	char	*tail;

	tail = (char *)str;
	while (*tail)
		if (*tail++ == c)
			return (tail - 1);
	if (*tail == c)
		return (tail);
	return (NULL);
}
