/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 13:08:16 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/09 19:08:30 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Returns a duplicate of a string that has had the white spaces before and
** after the string trimmed.
*/

char	*ft_strtrim(char const *s1)
{
	char			*sub;
	size_t			trimmed_space;
	unsigned int	index_start;

	if (!s1)
		return (NULL);
	trimmed_space = 0;
	while (s1[trimmed_space] == '\n' || s1[trimmed_space] == '\t' ||
			s1[trimmed_space] == ' ')
		trimmed_space++;
	if (!s1[trimmed_space])
		return (ft_strnew(0));
	index_start = trimmed_space;
	while (s1[trimmed_space])
		trimmed_space++;
	trimmed_space--;
	while (s1[trimmed_space] == '\n' || s1[trimmed_space] == '\t' ||
			s1[trimmed_space] == ' ')
		trimmed_space--;
	if (!(sub = ft_strsub(s1, index_start, (trimmed_space - index_start + 1))))
		return (NULL);
	return (sub);
}
