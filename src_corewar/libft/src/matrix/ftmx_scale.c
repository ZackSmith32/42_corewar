/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:41:42 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/03 13:41:57 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_matrix.h>
#include <memory.h>

/*
** mx_scale creates a scaling matrix of size len + 1. The inputs are an array
** of floats that will be used for scaling, and the len of the array.
*/

float	*mx_scale(float *sc, int len)
{
	float	*temp;
	int		dim;
	int		diag;
	int		i;

	dim = len + 1;
	if (!(temp = mx_id(dim)))
		return (NULL);
	diag = dim + 1;
	i = -1;
	while (++i < len)
		temp[(diag) * i] = sc[i];
	return (temp);
}
