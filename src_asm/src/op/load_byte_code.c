/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_byte_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 20:47:39 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/25 21:21:34 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** load_byte_code will load size bytes of value into the byte_code string
** in big endian order.
*/

char	*load_byte_code(intmax_t value, int size)
{
	char		*byte_code;
	char		*val;
	int			i;

	if (!(byte_code = (char*)ft_memalloc(size * sizeof(char))) || size > 8)
		return (NULL);
	val = (char*)&value;
	i = 0;
	while (size > 0)
	{
		size--;
		byte_code[i] = val[size];
		i++;
	}
	return (byte_code);
}
