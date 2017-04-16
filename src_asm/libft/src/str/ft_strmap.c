/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:27:08 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/29 07:37:53 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Applies function 'f' to each character of string 's' and returns a new
** string created from the succesive application of f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	char	*tail;

	if (!s || !f)
		return (NULL);
	if (!(map = ft_strnew(ft_strlen(s))))
		return (NULL);
	tail = map;
	while (*s)
		*tail++ = f(*(char *)s++);
	return (map);
}
