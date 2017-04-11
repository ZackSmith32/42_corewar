/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getint_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:31:42 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/11 16:40:03 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_type.h>
#include <ft_macro.h>

/*
** Assign digit converts a char into the appropriate digit for a base conversion
**	returns the number base if the character is invalid.
*/

int					ft_chartoi(char c, int base)
{
	int	digit;

	digit = (ft_isupper(c) ? 10 + (c - 'A') : base);
	digit = (ft_islower(c) ? 10 + (c - 'a') : digit);
	digit = (ft_isdigit(c) ? c - '0' : digit);
	return (digit);
}

/*
** ft_strd_ull_base starts at the first digit position of a number in a string
** and converts the number to the appropriate base, returns the string at the
** end of the number.
*/

unsigned long long	ft_strd_ull_base(char **str, int base)
{
	unsigned long long	result;
	unsigned long long	temp;
	int					digit;

	result = 0;
	while ((digit = ft_chartoi(**str, base)) < base)
	{
		temp = result;
		if ((result = (base * result) + (digit % base)) < temp)
			return (temp);
		(*str)++;
	}
	return (result);
}

/*
** ft_getll_base grabs the next number in str and assigns it to nbr.
*/

int					ft_getll_base(char **str, long long *nbr)
{
	unsigned long long	result;
	int					base;
	int					neg;

	if (!(str))
		return (0);
	while (ft_iswhitespace(**str))
		(*str)++;
	neg = (**str == '-' ? -1 : 1);
	if (**str == '-' || **str == '+')
		(*str)++;
	base = (**str == '0' ? 8 : 10);
	while (**str == '0')
		(*str)++;
	if ((**str == 'x' && base == 8) || (**str == 'X' && base == 8))
		base = ((*str)++ ? 16 : 16);
	result = ft_strd_ull_base(str, base);
	*nbr = (long long)(result * neg);
	return (1);
}
