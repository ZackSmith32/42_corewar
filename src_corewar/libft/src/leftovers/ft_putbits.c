/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 10:59:20 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/09 18:42:07 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prints the bit_size bits of block. Useful for visulaizing bit wise
** opperations.
*/

void	ft_putbits(unsigned long long block, int bit_size)
{
	char	*bits;

	if (!(bits = ft_bitstoa(block, bit_size)))
		ft_putstr("ft_putbits could not allocate enough space");
	else
		ft_putstr(bits);
}
