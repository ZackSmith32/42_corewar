/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:51:00 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 12:39:58 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Concatenates string 2 to the end of string 1, can cause major issues if
** there is not enough space at the end of string 1 to place string 2.
** Generally is a better idea to use ft_strlcat instead.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	char		*tail;
	const char	*srctail;

	tail = s1;
	srctail = s2;
	while (*tail)
		tail++;
	while (*srctail)
		*tail++ = *srctail++;
	*tail = '\0';
	return (s1);
}
