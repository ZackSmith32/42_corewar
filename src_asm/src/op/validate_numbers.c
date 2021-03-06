/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:26:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/27 14:21:28 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <limits.h>

/*
** Will return an error if anything but the proper number is given.
*/

static int	validate_atouintmax(uintmax_t *ret, char *str)
{
	uintmax_t	temp;

	*ret = 0;
	temp = 0;
	if (!(*str))
		return (1);
	while (ft_isdigit(*str))
	{
		temp = *ret;
		*ret = 10 * *ret + ((*str++ - '0') % 10);
		if (*ret / 10 != temp)
			return (1);
	}
	if (*str)
		return (1);
	return (0);
}

/*
** Boolean function for detecting hex characters
*/

static int	ishex(char c)
{
	if ((c <= 'f' && c >= 'a'))
		return (1);
	return (0);
}

/*
** atouintmax function for hexadecimal values
*/

static int	validate_atouintmax_hex(uintmax_t *ret, char *str)
{
	uintmax_t	temp;
	uintmax_t	digit;

	*ret = 0;
	temp = 0;
	if (!(*str))
		return (1);
	while (ft_isdigit(*str) || ishex(*str))
	{
		temp = *ret;
		if (ishex(*str))
			digit = (*str - 'a' + 10) % 16;
		else
			digit = (*str - '0') % 16;
		*ret = 16 * *ret + digit;
		if (*ret / 16 != temp)
			return (1);
		str++;
	}
	if (*str)
		return (1);
	return (0);
}

/*
** Limited atoi that will return error on any improperly formatted number string
** 1: error
** 0: success
*/

int			validate_atointmax(intmax_t *ret, char *str)
{
	uintmax_t	temp;
	int			sign;

	sign = 1;
	if (str[0] == '0' && str[1] == 'x')
	{
		if ((validate_atouintmax_hex(&temp, str + 2)) || temp > LONG_MAX)
			return (1);
	}
	else
	{
		if (*str == '-')
		{
			sign = -1;
			str++;
		}
		if ((validate_atouintmax(&temp, str)) || (sign == 1 && temp > LONG_MAX)
				|| (sign == -1 && temp > (INT_MAX + 1UL)))
			return (1);
	}
	*ret = sign * temp;
	return (0);
}
