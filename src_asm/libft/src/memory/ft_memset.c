/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:00:28 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 09:27:16 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Sets len bytes located at C-string b to the value of (unsigned char)c.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	char	*cast;

	cast = (char *)b;
	while (len-- > 0)
		*cast++ = (unsigned char)c;
	return (b);
}
