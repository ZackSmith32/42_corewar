/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:42:41 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/25 18:26:09 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Will return an error if anything but the proper number is given.
** 1: error
** 0: ok
*/

int	validate_atouintmax(uintmax_t *ret, char *str)
{
	uintmax_t	temp;

	*ret = 0;
	temp = 0;
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
** returns the number of bytes the parameter will take
*/

static int	get_size(const t_op *op, char c)
{
	int	size;

	size = IND_SIZE;
	if (c == DIRECT_CHAR && !op->dir_as_ind)
		size = DIR_SIZE;
	else if (c == 'r')
		size = REG_SIZE;
	return (size);
}

/*
** add_value appends either the register or numeric bytes to the output
**
** op:		Holds information on the op being parsed
** output:	Vector containing output byte array
** param:	Parameter being parsed
*/

int	add_param(const t_op *op, t_vec *output, char *param)
{
	uintmax_t	value;
	char		tag;
	int			size;

	tag = *param;
	size = get_size(op, tag);
	if (tag == DIRECT_CHAR || tag == 'r')
		param++;
	if (validate_atouintmax(&value, param) || (tag == 'r' && value > 99))
		return (1);
	ft_printf("\n\e[94mValue:%ju\e[0m\n", value);
	return (0);
	(void)output;
}
