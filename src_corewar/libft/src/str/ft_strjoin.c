/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 12:40:24 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/18 17:27:03 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Creates a new string that concatenates s1 and s2.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sub;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(sub = ft_strnew(s1_len + s2_len)))
		return (NULL);
	ft_strncpy(sub, s1, s1_len);
	ft_strncpy(sub + s1_len, s2, s2_len);
	return (sub);
}
