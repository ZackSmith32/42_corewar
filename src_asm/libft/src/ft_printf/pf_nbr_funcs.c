/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_diD.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:39:17 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/07 18:47:35 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_io.h"
#include "ft_memory.h"
#include "ft_string.h"

/*
** pf_ulltoa_base takes in a number as well as the precision and returns
** an allocated string.
*/

static char	*pf_ulltoa_base(unsigned long long n, int base, int size, char h)
{
	char	*result;
	char	*tail;
	char	mod;

	if (base > 32)
		return (NULL);
	if (!(result = ft_strnew(size)))
		return (NULL);
	tail = result;
	while (size-- > 0)
	{
		mod = n % base;
		if (mod > 9)
			*(tail + size) = mod + (h ? 'A' : 'a') - 10;
		else
			*(tail + size) = mod + '0';
		n /= base;
	}
	return (result);
}

/*
** Creates three different portions for the signed number string and attatches
** them all together. The three portions are sf (sign), p (precision), and nbr
** (number).
** NOTE: p.size is used to hold the length of the sign + the length of the
** precision string.
*/

int			pf_di(t_vdata *data, t_pfflag *fl, t_strvec *vec)
{
	uintmax_t	absdata;
	int			size;
	char		sf;

	sf = (fl->sf ? ' ' : 0);
	sf = (fl->pf ? '+' : sf);
	sf = (data->s < 0 ? '-' : sf);
	absdata = ft_absolute(data->s);
	size = ft_ullsize_base(absdata, 10);
	size = (size > fl->prcn ? size : fl->prcn);
	size = (data->s || fl->prcn || fl->zf ? size : 0);
	size = size + (!sf || (fl->zf && (fl->mfw >= size || !data->s)) ? 0 : 1);
	if (!(vec->str = pf_ulltoa_base(absdata, 10, size, 0)))
		return (-1);
	if (sf)
		vec->str[0] = sf;
	vec->len = size;
	return (vec->size = vec->len + 1);
}

/*
** pf_o allocates a string for octal arguments.
*/

int			pf_o(t_vdata *data, t_pfflag *fl, t_strvec *vec)
{
	int		size;
	char	hf;

	size = ft_ullsize_base(data->u, 8);
	hf = (fl->hf && size > fl->prcn && (data->u || !fl->prcn) ? 1 : 0);
	size = (size > fl->prcn ? size : fl->prcn);
	size = (data->u || fl->prcn || fl->zf ? size : 0);
	if (!(vec->str = pf_ulltoa_base(data->u, 8, size + hf, 0)))
		return (-1);
	vec->len = size + hf;
	return (vec->size = vec->len + 1);
}

/*
** pf_ub acts as a conversion for either binary or unsigned arguments.
*/

int			pf_ub(t_vdata *data, t_pfflag *fl, t_strvec *vec)
{
	int	size;
	int	base;

	base = (fl->conv != 'b' ? 10 : 2);
	size = ft_ullsize_base(data->u, base);
	size = (size > fl->prcn ? size : fl->prcn);
	size = (data->u || fl->prcn || fl->zf ? size : 0);
	if (!(vec->str = pf_ulltoa_base(data->u, base, size, 0)))
		return (-1);
	vec->len = ft_strlen(vec->str);
	return (vec->size = vec->len + 1);
}

/*
** Applies the appropriate flags to the x and p conversions. It should
** be noted that these conversions act slightly differently when the
** value of the argument is 0. Also if the zero flag is active then there
** is no need to increase the size for the hf, as size is already equal to
** the minimum field width.
*/

int			pf_xp(t_vdata *data, t_pfflag *fl, t_strvec *vec)
{
	int		s;
	char	hf;

	hf = (fl->conv == 'p' || (fl->hf && data->u) ? 2 : 0);
	s = ft_ullsize_base(data->u, 16);
	s = (s > fl->prcn ? s : fl->prcn);
	s = (data->u || fl->prcn || fl->zf ? s : 0);
	s = s + (fl->zf && (fl->mfw >= s || !data->u) ? 0 : hf);
	if (!(vec->str = pf_ulltoa_base(data->u, 16, s, (fl->conv == 'X' ? 1 : 0))))
		return (-1);
	if (hf)
		vec->str[1] = (fl->conv == 'X' ? 'X' : 'x');
	vec->len = s;
	return (vec->size = vec->len + 1);
}
