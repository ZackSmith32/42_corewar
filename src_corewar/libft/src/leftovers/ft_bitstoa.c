/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitstoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:26:07 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/17 09:13:14 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Converts bit_size bits into a string. Useful for when you want to keep
** track of the leading 0's in your type.
*/

static char	*static_bitloader(char *str, unsigned long long block, int bit_size)
{
	if (block < ft_power(2, bit_size + 1))
	{
		if (block / ft_power(2, bit_size) != 0)
		{
			*str = '1';
			block %= ft_power(2, bit_size);
		}
		else
			*str = '0';
	}
	else
		block %= ft_power(2, bit_size);
	if (bit_size != 0)
		static_bitloader(++str, block, --bit_size);
	return (str);
}

char		*ft_bitstoa(unsigned long long block, int bit_size)
{
	char	*result;

	if (bit_size == 0)
		return (NULL);
	result = ft_strnew(bit_size + 1);
	return (static_bitloader(result, block, bit_size));
}
