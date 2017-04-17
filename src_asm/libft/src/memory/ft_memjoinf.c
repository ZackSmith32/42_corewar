/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:29:34 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/11 16:37:47 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <string.h>

/*
** Creates a new C string that is a combination of s1 and s2, then frees both
** the old C strings. Also free both strings and return NULL in cases where
** not enough memory can be allocated.
*/

void	*ft_memjoinf(void *s1, void *s2, size_t n1, size_t n2)
{
	void	*result;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	if (!(result = ft_memreallocf(s1, n1 + n2, n1)))
	{
		ft_memdel(&s2);
		return (NULL);
	}
	ft_memmove(result + n1, s2, n2);
	ft_memdel(&s2);
	return (result);
}
