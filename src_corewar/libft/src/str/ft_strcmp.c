/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:10:00 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 10:20:41 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Compares two strings and returns the difference between the first two
** differing characters.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] == str2[i] && (str1[i] != 0 && str2[i] != 0))
		i++;
	if (str1[i] == 0 && str2[i] == 0)
		return (0);
	return (str1[i] - str2[i]);
}
