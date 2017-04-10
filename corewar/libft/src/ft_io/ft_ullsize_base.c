/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullsize_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:45:53 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/10 13:37:24 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** ft_ullsize_base calculates the number of characters present in an unsigned
** long long for the particular base.
*/

size_t	ft_ullsize_base(unsigned long long value, unsigned long long base)
{
	size_t	size;

	if (base == 1)
		return (value);
	size = 1;
	while (value / base != 0)
	{
		size++;
		value /= base;
	}
	return (size);
}
