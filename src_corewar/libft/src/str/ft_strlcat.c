/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 16:47:21 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/06 13:32:43 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
** Takes in the 'size' of the buffer as an input and concatinates string 2 to
** the end of string 1, up until the buffer runs out of space. Returns the
** size of the buffer that it tried to concatenate.
*/

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	char		*tail;
	const char	*srctail;
	size_t		size_anchor;

	tail = s1;
	srctail = s2;
	size_anchor = size;
	while (*tail)
	{
		size--;
		tail++;
		if (size == 0 || (size + 1) == 0)
			return (size_anchor + ft_strlen(srctail));
	}
	while (*srctail && size-- > 1)
		*tail++ = *srctail++;
	*tail = '\0';
	if (*srctail)
		return (size_anchor + ft_strlen(srctail) - 1);
	return (ft_strlen(s1));
}
