/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrrmv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:10:10 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/17 09:18:23 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Removes all instances of char c from str.
*/

char	*ft_strchrrmv(char *str, char c)
{
	int		newlen;
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	newlen = ft_strlen(str) - ft_strctchr(str, c);
	result = ft_strnew(newlen);
	while (str[i])
	{
		if (str[i] != c)
			result[j++] = str[i];
		i++;
	}
	return (result);
}
