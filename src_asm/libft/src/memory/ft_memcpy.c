/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:48:15 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/08 13:05:12 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Copies 'n' bytes from the src C-string to the dst C-string.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tail;
	char	*srctail;

	tail = (char *)dst;
	srctail = (char *)src;
	while (n > 0)
	{
		*tail = *srctail;
		tail++;
		srctail++;
		n--;
	}
	return (dst);
}
