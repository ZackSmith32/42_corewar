/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:19:56 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 09:50:19 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
** Converts a string to its respective unsigned int value.
*/

unsigned int	ft_atoui(const char *str)
{
	return ((unsigned int)ft_atoull(str));
}
