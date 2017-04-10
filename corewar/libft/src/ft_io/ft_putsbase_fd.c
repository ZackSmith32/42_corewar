/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsbase_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:47:38 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 09:56:45 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
** Takes a signed long long and prints it into the appropriate
** file directory in the specified base up to 32.
*/

void	ft_putsbase_fd(long long n, long long base, int fd, char hex)
{
	if (base > 32)
		return ;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n > (base - 1) || n < -(base - 1))
	{
		ft_putsbase_fd(ft_absolute(n / base), base, fd, hex);
		ft_putsbase_fd(ft_absolute(n % base), base, fd, hex);
	}
	else if (n <= 9)
		ft_putchar_fd((ft_absolute(n) + '0'), fd);
	else if (hex == 0)
		ft_putchar_fd((ft_absolute(n) + 'a' - 10), fd);
	else if (hex == 1)
		ft_putchar_fd((ft_absolute(n) + 'A' - 10), fd);
}
