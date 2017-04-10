/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_negflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 13:10:09 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/05 13:12:38 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Flags n as negative or not, as well as changes the value from negative n
** to positive n.
*/

void	ft_negflag(int *n, int *negative)
{
	if (*n < 0)
	{
		*negative = 1;
		*n = -*n;
	}
	else
		*negative = 0;
}
