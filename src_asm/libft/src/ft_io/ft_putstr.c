/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 10:39:21 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 09:57:13 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

/*
** 'Write' a string to the standard output.
*/

void	ft_putstr(char const *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return ;
	}
	write(1, s, ft_strlen(s));
}
