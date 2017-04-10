/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:15:32 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/03 15:42:29 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_matrix.h>
#include <stdlib.h>

/*
** mx_id creates an identity matrix of size dim x dim.
*/

float	*mx_id(int dim)
{
	float	*temp;
	int		size;
	int		diagonal;
	int		i;

	size = dim * dim;
	diagonal = dim + 1;
	if (!(temp = (float*)malloc(sizeof(float) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		temp[i] = (i % diagonal ? 0 : 1);
	return (temp);
}
