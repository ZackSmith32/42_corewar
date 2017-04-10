/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 11:46:14 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/02 14:06:56 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Uses the ft_strncmp function to compare 'n' characters of two strings.
** If the portions compared are identical then return 1, else return 0.
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
