/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 14:10:46 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/08 20:25:54 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Raises nbr by the power.
*/

unsigned long long	ft_power(unsigned long long nbr, int power)
{
	unsigned long long	result;

	if (power == 0)
		return (1);
	result = ft_power(nbr, power / 2);
	if (power % 2 == 0)
		return (result * result);
	else
		return (nbr * result * result);
}
