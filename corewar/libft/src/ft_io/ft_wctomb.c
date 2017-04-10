/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:41:24 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/03 15:56:59 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

/*
** ft_wctomb translates a wide character it into a multibyte character which
** is stored in s. s must have enough space to store the multibyte character.
** It translates by taking the wide char and parsing out the data into
** individual bytes in an array with the appropriate tags placed on them.
*/

int	ft_wctomb(char *s, wchar_t wc)
{
	int	bytes;

	if (!s)
		return (0);
	bytes = 0;
	if (wc > 0x10FFFF || (wc >= 0xD800 && wc <= 0xDFFF))
		return (-1);
	if (wc > 0xFFFF)
		*(s + bytes++) = 0xF0 | ((wc & 0x1C0000) >> 18);
	if (wc > 0x7FF)
		*(s + bytes++) = (wc <= 0xFFFF ? 0xE0 : 0x80) | ((wc & 0x3F000) >> 12);
	if (wc > 0x7F)
		*(s + bytes++) = (wc <= 0x7FF ? 0xC0 : 0x80) | ((wc & 0xFC0) >> 6);
	if (wc >= 0x00)
		*(s + bytes++) = (wc <= 0x7F ? 0x0 | (wc & 0x7F) : 0x80 | (wc & 0x3F));
	return (bytes);
}
