/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:57:34 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/07 18:31:52 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_io.h"
#include "ft_type.h"
#include "ft_printf.h"
#include <stdarg.h>

/*
** pf_islm checks to see if the current character in the format string is
** a flag, or a length modifier character.
*/

static int			pf_isflmc(char c)
{
	if (ft_strchr(FLAGS, c) || ft_strchr(LM, c))
		return (1);
	if (ft_strchr(CHARCONVERSION, c))
		return ('c');
	if (ft_strchr(STRCONVERSION, c))
		return ('p');
	if (ft_strchr(SNUMCONVERSION, c))
		return ('s');
	if (ft_strchr(UNUMCONVERSION, c))
		return ('u');
	return (0);
}

/*
** pf_set_lm sets the length modifier flag. It prioritzes types of larger
** values. If the current character is an h, and the length modifier is already
** set for 'h' then change the lm to indicate the prescence of 'hh'. Do a
** similar thing for 'l' and 'll' as well.
** lm[-1, 0, 1, 2, 3, 4, 5] = [no lm, hh, h, l, ll, j, z]
*/

static int			pf_set_lm(const char *fstr, int lm)
{
	int	tmp;

	tmp = -1;
	if (*fstr == 'h' && lm == 1)
		lm = 0;
	else if (*fstr == 'h')
		tmp = 1;
	else if (*fstr == 'l' && lm == 2)
		tmp = 3;
	else if (*fstr == 'l')
		tmp = 2;
	else if (*fstr == 'z')
		tmp = 4;
	else if (*fstr == 'j')
		tmp = 5;
	if (tmp > lm)
		return (tmp);
	return (lm);
}

/*
** pf_fs_end returns a pointer to the first non flag/non digit character in
** a format string (this character will either be a conversion or
** not a conversion). It will also turn on any flags present as well as set
** the minimum field width and presicion. Will also set either the l or h lm
** modifier flag. A flag with a negative value indicates a lack of the
** flag.
*/

static const char	*pf_fs_end(const char *str, t_pfflag *fl, int d)
{
	while (((d = ft_isdigit(*str)) || pf_isflmc(*str) == 1) && *str)
	{
		fl->hf = (*str == '#' ? 1 : fl->hf);
		fl->mf = (*str == '-' ? 1 : fl->mf);
		fl->zf = (*str == '0' ? 1 : fl->zf);
		fl->pf = (*str == '+' ? 1 : fl->pf);
		fl->sf = (*str == ' ' ? 1 : fl->sf);
		fl->mfw = (d && *str != '0' ? ft_atoi(str) : fl->mfw);
		fl->prcn = (*str == '.' ? ft_atoi(str + 1) : fl->prcn);
		fl->lm = pf_set_lm(str, fl->lm);
		if ((d && *str != '0') || (*str == '.' && ft_isdigit(*(str + 1))))
			while (ft_isdigit(*++str))
				;
		else
			str++;
	}
	fl->conv = *str;
	fl->is_con = pf_isflmc(*str);
	fl->lm = (ft_strchr(LCONVERSION, fl->conv) ? 2 : fl->lm);
	fl->zf = (fl->is_con >= 's' && fl->prcn != -1 ? 0 : fl->zf);
	fl->zf = (fl->mf ? 0 : fl->zf);
	fl->sf = (fl->pf ? 0 : fl->sf);
	fl->prcn = (fl->is_con >= 's' && fl->zf ? fl->mfw : fl->prcn);
	fl->prcn = (fl->is_con > 'c' ? fl->prcn : -1);
	return (str);
}

/*
** pf_getdata assigns the data of the conersion argument to the appropriate
** type. It also does some post flag reading modifications.
*/

static t_vdata		pf_getdata(t_pfflag *fl, va_list ap)
{
	t_vdata	data;

	data.c = (fl->is_con == 'c' ? va_arg(ap, wint_t) : 0);
	data.p = (fl->is_con == 'p' ? va_arg(ap, char *) : 0);
	data.s = (fl->is_con == 's' ? va_arg(ap, intmax_t) : 0);
	data.u = (fl->is_con == 'u' ? va_arg(ap, uintmax_t) : 0);
	if (fl->is_con == 's')
	{
		data.s = (fl->lm == -1 ? (int)data.s : data.s);
		data.s = (fl->lm == 0 ? (char)data.s : data.s);
		data.s = (fl->lm == 1 ? (short)data.s : data.s);
		data.s = (fl->lm == 2 ? (long)data.s : data.s);
		data.s = (fl->lm == 3 ? (long long)data.s : data.s);
		data.s = (fl->lm == 4 ? (ssize_t)data.s : data.s);
	}
	else if (fl->is_con == 'u' && fl->conv != 'p')
	{
		data.u = (fl->lm == -1 ? (unsigned int)data.u : data.u);
		data.u = (fl->lm == 0 ? (unsigned char)data.u : data.u);
		data.u = (fl->lm == 1 ? (unsigned short)data.u : data.u);
		data.u = (fl->lm == 2 ? (unsigned long)data.u : data.u);
		data.u = (fl->lm == 3 ? (unsigned long long)data.u : data.u);
		data.u = (fl->lm == 4 ? (size_t)data.u : data.u);
	}
	return (data);
}

/*
** pf_read_format sets the fflag->conv to the last value of the format string,
** and converts the length modifier for DOUSC to 'l'.
*/

const char			*pf_read_format(const char *fstr, va_list ap, t_strvec *h)
{
	t_vdata		vdata;
	t_pfflag	fflag;
	const char	*tail;
	const char	*index_head;

	ft_bzero(&fflag, sizeof(fflag));
	fflag.lm = -1;
	fflag.prcn = -1;
	tail = pf_fs_end(fstr, &fflag, 0);
	if (!(*tail))
		return (tail);
	vdata = pf_getdata(&fflag, ap);
	index_head = CONVERSIONS;
	if (fflag.is_con > 1)
		fflag.findex = ft_strchr(index_head, fflag.conv) - index_head;
	if ((pf_append_data(&vdata, &fflag, h)) == -1)
		return (NULL);
	return (tail + 1);
}
