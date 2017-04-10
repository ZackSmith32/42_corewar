/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:29:32 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/03 13:36:24 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_matrix.h>
#include <memory.h>

/*
** mx_translate creates a matrix used for translation. It receives an array
** of floats as well as the length of the array. It then creates an identity
** matrix of size (len + 1), and fills the bottom row of the matrix with the
** values in the float array.
*/

float	*mx_translate(float *tr, int len)
{
	float	*temp;
	int		dim;
	int		offset;
	int		i;

	dim = len + 1;
	if (!(temp = mx_id(dim)))
		return (NULL);
	offset = dim * len;
	i = -1;
	while (++i < len)
		temp[offset + i] = tr[i];
	return (temp);
}
