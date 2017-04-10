/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 18:33:58 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 09:41:09 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Copies 'len' characters from src into dst. If len is larger than src then
** the remaining characters copied are '\0'.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	index--;
	while (++index < len)
		dst[index] = '\0';
	return (dst);
}
