/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 15:30:05 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 12:41:13 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Concatenates 'n' characters from s2 to the end of s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*tail;
	const char	*srctail;

	tail = s1;
	srctail = s2;
	while (*tail)
		tail++;
	while (*srctail && n-- > 0)
		*tail++ = *srctail++;
	*tail = '\0';
	return (s1);
}
