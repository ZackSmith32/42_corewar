/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2017/04/13 14:56:21 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void				change_end(void *val, size_t size)
{
	uint8_t swap;
	uint8_t *start;
	uint8_t	*end;

	start = (uint8_t*)val;
	end = start + size - 1;
	while (end > start)
	{
		swap = *start;
		*start = *end;
		*end = swap;
		end--;
		start++;
	}
}

int					ft_jasprintf(t_strvec *ret, const char *format, ...)
{
	va_list		ap;
	int			size;

	va_start(ap, format);
	size = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (size);
}
