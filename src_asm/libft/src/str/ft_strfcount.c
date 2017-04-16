/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsplcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:29:32 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/28 18:54:31 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Counts the number of chunks delimited by the characters specified by function
**	dchar.
*/

unsigned int		ft_strfcount(const char *s, int (*dchar)(int))
{
	unsigned int	word_count;

	word_count = 0;
	while (*s)
	{
		while (dchar(*s) && *s)
			s++;
		while (!(dchar(*s)) && *s)
			s++;
		word_count++;
	}
	if (dchar(*(s - 1)))
		word_count--;
	return (word_count);
}
