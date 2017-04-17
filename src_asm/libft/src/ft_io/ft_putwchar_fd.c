/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:32:46 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/11 16:41:48 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_memory.h"
#include <unistd.h>
#include <wchar.h>

/*
** ft_putwchar_fd takes a wchar_t argument and uses ft_wctomb to convert the
** wide character into a multibyte string, which it then writes to the
** appropriate file descriptor.
*/

wint_t	ft_putwchar_fd(wchar_t wc, int fd)
{
	char	bytes[4];
	int		n_bytes;

	ft_bzero(bytes, 4);
	if ((n_bytes = ft_wctomb(bytes, wc)) == -1)
		return (WEOF);
	else
		write(fd, bytes, n_bytes);
	return (wc);
}
