/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf(wrapper).c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:49:50 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 15:50:40 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

/*
** Wrapper version of ft_printf, which prints the format string to stdout.
*/

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	size = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (size);
}
