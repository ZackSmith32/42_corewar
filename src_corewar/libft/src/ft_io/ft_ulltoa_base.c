/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:05:51 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/11 16:41:03 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"
#include <string.h>

/*
** Converts an unsigned long long into a character string from base 2-32.
** If h is on then print capital characters for base is greater than 10.
*/

char	*ft_ulltoa_base(unsigned long long n, int base, char h)
{
	char	*result;
	char	*tail;
	size_t	size;
	char	mod;

	if (base > 32)
		return (NULL);
	size = ft_ullsize_base(n, base);
	if (!(result = ft_strnew(size)))
		return (NULL);
	tail = result;
	while (size-- > 0)
	{
		mod = n % base;
		if (mod > 9)
			*(tail + size) = mod + (h ? 'A' : 'a') - 10;
		else
			*(tail + size) = mod + '0';
		n /= base;
	}
	return (result);
}
