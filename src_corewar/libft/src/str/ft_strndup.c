/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:03:14 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/02 20:52:35 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Duplicates n characters from the string into a seperate string.
*/

char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;

	return ((result = ft_strnew(n)) ? ft_strncpy(result, s1, n) : NULL);
}
