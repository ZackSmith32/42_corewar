/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:42:41 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 13:37:04 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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
		size = 1;
	return (size);
}

/*
** add_value appends either the register or numeric bytes to the output
**
** op:		Holds information on the op being parsed
** output:	Vector containing output byte array
** param:	Parameter being parsed
*/

int			add_param(const t_op *op, t_vec *output, char *param)
{
	intmax_t	value;
	char		tag;
	char		*byte_code;
	int			size;
	int			ret;

	tag = *param;
	size = get_size(op, tag);
	if (tag == DIRECT_CHAR || tag == 'r')
		param++;
	if (validate_atointmax(&value, param) ||
			(tag == 'r' && (value > 99 || value < 0)))
		return (1);
	if (!(byte_code = load_byte_code(value, size)))
		return (1);
	ret = ft_vecapp(output, byte_code, size);
	free(byte_code);
	return (ret ? 0 : 1);
}
