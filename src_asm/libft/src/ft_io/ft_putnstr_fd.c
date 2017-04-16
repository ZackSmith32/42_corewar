/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:25:48 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 09:55:06 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

/*
** ft_putnstr_fd will write either the maximum length of str, or n characters
** of str, whichever is shorter.
*/

void	ft_putnstr_fd(int fd, char *str, size_t n)
{
	int		strlen;

	strlen = ft_strlen(str);
	if (strlen > n)
		write(fd, str, n);
	else
		write(fd, str, strlen);
}
