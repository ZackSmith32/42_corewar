/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:13:30 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/17 09:19:35 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Trims char c from the front and back of str.
*/

char	*ft_strctrim(char *str, char c)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (*str == c)
		str++;
	while (str[i])
		i++;
	i--;
	while (str[i] == c && i >= 0)
		i--;
	if (!(res = ft_strsub(str, 0, i + 1)))
		return (NULL);
	return (res);
}
