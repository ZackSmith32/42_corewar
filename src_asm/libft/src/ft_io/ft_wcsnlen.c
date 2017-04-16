/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:45:49 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/11 16:40:47 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <wchar.h>

/*
** ft_wcsnlen checks n bytes of a wide character string for the prescence
** of invalid characters.
*/

size_t	ft_wcsnlen(const wchar_t *wcs, size_t n)
{
	size_t	converted_char;
	int		current_char;
	char	temp[4];

	converted_char = 0;
	while (*wcs)
	{
		if ((current_char = ft_wctomb(temp, *wcs++)) == -1)
			return ((size_t)-1);
		if ((converted_char + current_char) > n)
			break ;
		converted_char += current_char;
	}
	return (converted_char);
}
