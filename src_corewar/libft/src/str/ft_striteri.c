/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 13:11:11 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 12:40:43 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function 'f' to each character in a string
** starting at the index passed as the first argument.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int index;

	if (!s || !f)
		return ;
	index = -1;
	while (s[++index])
		f(index, &s[index]);
}
