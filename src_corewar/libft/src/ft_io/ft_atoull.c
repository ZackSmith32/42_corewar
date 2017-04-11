/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:51:52 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 09:49:20 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

/*
** Converts a string to its respective unsigned long long value.
*/

unsigned long long	ft_atoull(const char *str)
{
	unsigned long long	result;
	unsigned long long	temp;

	result = 0;
	temp = 0;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '+')
		str++;
	while (ft_isdigit(*str - 0))
	{
		temp = result;
		result = 10 * result + ((*str++ - '0') % 10);
		if (result < temp)
			return (temp);
	}
	return (result);
}
