/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:23:06 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/08 13:51:10 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_memory.h"
#include "ft_string.h"
#include <stdarg.h>

/*
** Think of making a struct to store front middle and end of result string.
*/

static int			pf_cleanup(int result, va_list ap,
		t_strvec *tail, t_strvec *ret)
{
	if (result >= 0)
	{
		if ((ret->size = ft_strvgrow(ret, result)) != (size_t)-1)
			ft_memmove(ret->str + ret->len, tail->str, tail->len);
		ret->len = result;
	}
	ft_memdel((void *)&tail->str);
	(ap ? va_end(ap) : 0);
	if (ret->size == (size_t)-1)
		return (-1);
	return (result);
}

/*
** pf_putcstr cycles through the format string until it encounters a '%'
** character, at which time it allocates a string for the portion of
** the format string up until that point.
*/

static const char	*pf_putcstr(const char *str, t_strvec *sv)
{
	char	*pp;

	if (!(pp = ft_strchr((const char *)str, '%')))
		sv->len = ft_strlen(str);
	else
		sv->len = pp - str;
	if (!(sv->str = ft_strndup(str, sv->len)))
		return (NULL);
	sv->size = sv->len + 1;
	return (pp);
}

/*
** ft_vasprintf takes assigns a format string to the string located in a strvec
** struct.
*/

int					ft_vasprintf(t_strvec *ret, const char *format, va_list ap)
{
	t_strvec	tail;
	int			result;

	ft_bzero((void *)&tail, sizeof(tail));
	pf_farray(0);
	while ((format = pf_putcstr(format, &tail)))
	{
		if (!*(++format))
			return (pf_cleanup(ret->len + tail.len, ap, &tail, ret));
		if (!(format = pf_read_format(format, ap, &tail)))
			return (pf_cleanup(-1, ap, &tail, ret));
		if ((ret->size = ft_strvgrow(ret, ret->len + tail.len)) == (size_t)-1)
			return (pf_cleanup(-1, ap, &tail, ret));
		ft_memmove(ret->str + ret->len, tail.str, tail.len);
		ret->len += tail.len;
		free(tail.str);
	}
	result = ((tail.str) ? ret->len + tail.len : -1);
	return (pf_cleanup(result, ap, &tail, ret));
}
