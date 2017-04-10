/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llsize_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:54:28 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 09:50:53 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_io.h"

/*
** ft_llsize_base calculates the number of characters present in an
** long long for the particular base. Increases the size if the value is
** negative to accomadate the '-' character, or if the sflag is on to
** accomadate for either the '+' or ' ' characters.
** Generally if you are dealing with non base 10 numbers you should use
** the unsigned size function.
*/

size_t	ft_llsize_base(long long value, long long base, int sflag)
{
	size_t	size;

	if (base < 0)
		return (0);
	if (base == 1)
		return (ft_absolute(value));
	size = 1;
	if (value < 0 || sflag)
		size++;
	while (value / base != 0)
	{
		size++;
		value /= base;
	}
	return (size);
}
