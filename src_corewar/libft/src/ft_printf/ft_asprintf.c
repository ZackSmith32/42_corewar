/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:50:56 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/07 17:27:27 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include <stdarg.h>

/*
** Allocates a string that holds the format string inside.
*/

int	ft_asprintf(char **ret, const char *format, ...)
{
	va_list		ap;
	t_strvec	result;
	int			size;

	va_start(ap, format);
	size = ft_vasprintf(&result, format, ap);
	va_end(ap);
	if (!(*ret = ft_strndup(result.str, result.len)))
		return (-1);
	ft_memdel((void *)&result.str);
	return (size);
}
