/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:01:39 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/29 09:02:10 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Compares 'n' characters between two strings and returns the difference
** of the first two differing characters.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && n-- > 1 && (str1[i] != 0 && str2[i] != 0))
		i++;
	if (str1[i] == 0 && str2[i] == 0)
		return (0);
	return (str1[i] - str2[i]);
}
