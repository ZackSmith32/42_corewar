/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:59:31 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/07 18:37:42 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_printf.h"
#include "ft_string.h"
#include <stdarg.h>
#include <wchar.h>

/*
** Prints characters or wide characters.
*/

int			pf_c(t_vdata *data, t_pfflag *fl, t_strvec *vec)
{
	int		size;
	char	c[4];

	if (fl->lm == 2)
	{
		if ((size = ft_wctomb(c, data->c)) == -1)
			return (-1);
		if (!(vec->str = ft_strndup(c, size)))
			return (-1);
	}
	else
	{
		c[0] = (unsigned char)data->c;
		size = 1;
		if ((!(vec->str = ft_strndup(c, 1))))
			return (-1);
	}
	vec->len = size;
	return (vec->size = vec->len + 1);
}

/*
** pf_slen is a helper function for pf_s. It determines the length of
** the string to print based on the presicion flag.
*/

static int	pf_slen(t_pfflag *fl, int size)
{
	if (fl->prcn != -1)
		return (size > fl->prcn ? fl->prcn : size);
	return (size);
}

/*
** pf_s allocates memory to hold a string of characters or wide characters.
*/

int			pf_s(t_vdata *data, t_pfflag *fl, t_strvec *vec)
{
	wchar_t	*head;
	wchar_t	*tail;

	if (fl->lm == 2 && data->p)
	{
		head = (wchar_t *)data->p;
		tail = head;
		while (*tail)
			tail++;
		vec->len = pf_slen(fl, sizeof(wchar_t) * (tail - head));
		if (!(vec->str = ft_strnew(vec->len)))
			return (-1);
		if ((vec->len = ft_wcstombs(vec->str, head, vec->len)) == (size_t)-1)
			return (pf_alloc_ret(-1, vec->str, NULL, NULL));
	}
	else
	{
		vec->len = pf_slen(fl, (data->p ? ft_strlen(data->p) : 6));
		if (!(vec->str = ft_strndup((data->p ? data->p : "(null)"), vec->len)))
			return (-1);
	}
	return (vec->size = vec->len + 1);
}
