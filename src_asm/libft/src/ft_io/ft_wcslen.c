/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:15:38 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/26 20:27:54 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <wchar.h>

/*
** ft_wcslen returns the length of the wcharacter string.
*/

size_t	ft_wcslen(const wchar_t *wcs)
{
	size_t	converted_char;
	int		current_char;
	char	temp[4];

	converted_char = 0;
	while (*wcs)
	{
		if ((current_char = ft_wctomb(temp, *wcs++)) == -1)
			return ((size_t)-1);
		converted_char += current_char;
	}
	return (converted_char);
}
