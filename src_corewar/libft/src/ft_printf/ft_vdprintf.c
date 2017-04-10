/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:48:13 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/08 13:51:14 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include <stdarg.h>
#include <unistd.h>

/*
** Takes an argument list and prints the format string into the appropriate
** file descriptor.
*/

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_strvec	ret;
	int			size;

	ft_bzero((void *)&ret, sizeof(ret));
	size = ft_vasprintf(&ret, format, ap);
	write(fd, ret.str, ret.len);
	ft_memdel((void *)&ret.str);
	return (size);
}
