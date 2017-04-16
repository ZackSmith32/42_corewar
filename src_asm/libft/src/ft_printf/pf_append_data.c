/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_append_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:37:18 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/08 13:51:16 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_memory.h"
#include "ft_string.h"

/*
** conv_literal converts a non conversion character into a string containing
** the conversion character.
*/

static int		conv_literal(t_pfflag *fl, t_strvec *lit)
{
	if (!(lit->str = ft_strnew(1)))
		return (-1);
	*(lit->str) = fl->conv;
	lit->len = 1;
	return ((lit->size = 2));
}

/*
** pad_str creates the padding portion of the conversion string.
*/

static t_strvec	*pad_str(t_pfflag *fl, t_strvec *tail, t_strvec *padding)
{
	char	padchar;

	padding->len = ((fl->mfw - (ssize_t)tail->len) < 0 ? 0
			: fl->mfw - tail->len);
	if (padding->len)
	{
		padchar = (fl->zf && fl->is_con < 's' ? '0' : ' ');
		if (!(padding->str = ft_strnew(padding->len)))
			return (NULL);
		ft_memset((void *)padding->str, padchar, padding->len);
	}
	else
		padding->str = NULL;
	padding->size = (padding->len ? padding->len + 1 : 0);
	return (padding);
}

/*
** Create a conversion string and a padding string then add them to the head
** string in the appropriate order. NOTE: tail->size is accounting for the final
** null terminator for allocation purposes of the string.
** h = head portion of the allocated string (holds the preconversion portion)
** p = the padding portion of the conversion string.
** tail = the non-padding portion of the conversion string.
*/

int				pf_append_data(t_vdata *data, t_pfflag *fl, t_strvec *h)
{
	t_strvec	tail;
	t_strvec	p;

	if (fl->is_con > 1)
	{
		if (g_farray[fl->findex](data, fl, &tail) < 0)
			return (-1);
	}
	else if (conv_literal(fl, &tail) < 0)
		return (-1);
	if (!(pad_str(fl, &tail, &p)))
		return (pf_alloc_ret(-1, tail.str, NULL, NULL));
	if ((h->size = ft_strvgrow(h, h->len + p.len + tail.size)) == (size_t)-1)
		return (pf_alloc_ret(-1, tail.str, p.str, NULL));
	if (fl->mf || !p.len)
		ft_memmove(h->str + h->len, tail.str, tail.size);
	if (fl->mf && p.len)
		ft_memmove(h->str + h->len + tail.len, p.str, p.size);
	else if (p.len)
	{
		ft_memmove(h->str + h->len, p.str, p.size);
		ft_memmove(h->str + h->len + p.len, tail.str, tail.size);
	}
	return (pf_alloc_ret((h->len += p.len + tail.len), tail.str, p.str, NULL));
}
