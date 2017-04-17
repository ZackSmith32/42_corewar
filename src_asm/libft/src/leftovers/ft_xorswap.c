/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xorswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 09:27:32 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/09 09:38:05 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_xorswap uses the xor bit operator to swap the values of two pointers.
*/

void	ft_xorswapi(int *a, int *b)
{
	if (a && b && a != b)
	{
		*a = *a ^ *b;
		*b = *b ^ *a;
		*a = *a ^ *b;
	}
}
