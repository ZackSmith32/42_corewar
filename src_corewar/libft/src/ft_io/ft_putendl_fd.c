/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 10:44:19 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 09:53:36 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

/*
** 'Writes' a string with a new line at the end into the appropriate
** file directory.
*/

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
	{
		write(1, "(null)\n", 7);
		return ;
	}
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
