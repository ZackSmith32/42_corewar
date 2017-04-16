/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 10:17:05 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 12:40:10 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sets every character ina string to the value '\0'.
*/

void	ft_strclr(char *s)
{
	if (!s)
		return ;
	ft_bzero(s, (ft_strlen(s) + 1));
}
