/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:43:47 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/29 07:38:54 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Applies function 'f' to each character of string 's' and returns a new
** string created from the succesive application of f. The first argument in
** the function is the index of the string.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	index;

	if (!s || !f)
		return (NULL);
	if (!(map = ft_strnew(ft_strlen(s))))
		return (NULL);
	index = -1;
	while (s[++index])
		map[index] = f(index, (char)s[index]);
	return (map);
}
