/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:49:05 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 09:47:37 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
** Converts a string of numbers into an int. If the value of the digit string
** is larger than max long long or smaller than min long long return -1 or 0
** respectivley.
*/

int	ft_atoi(const char *str)
{
	return ((int)(ft_atoll(str)));
}
