/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:44:18 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 09:56:26 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <wchar.h>

/*
** ft_putnwstr_fd will write up to n bytes of the wstr, returns the number of
** bytes it wrote, or a negative one if a invalid character is encountered.
*/

size_t	ft_putnwstr_fd(wchar_t *wstr, size_t n, int fd)
{
	size_t	converted_char;
	int		current_char;
	char	temp[4];

	converted_char = 0;
	while (*wstr)
	{
		if ((current_char = ft_wctomb(temp, *wstr)) == -1)
			return ((size_t)-1);
		if ((converted_char + current_char) <= n)
			ft_putwchar_fd(*wstr, fd);
		else
			return (converted_char);
		wstr++;
		converted_char += current_char;
	}
	return (converted_char);
}
