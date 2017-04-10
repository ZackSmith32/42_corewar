/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 10:27:01 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/24 10:30:29 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** 'writes' a character into the appropriate file directory.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
