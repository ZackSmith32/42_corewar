/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:36:02 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 09:36:51 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Finds the length of a string.
*/

size_t	ft_strlen(const char *s)
{
	const char	*tail;

	tail = s;
	while (*tail)
		tail++;
	return (tail - s);
}
