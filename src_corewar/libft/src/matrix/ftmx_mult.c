/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_4x4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 14:35:51 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/03 15:59:22 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_matrix.h>
#include <ft_memory.h>

/*
** matrix_mult will multiply the matrices in the order: M1 X M2. the number of
** columns for m1 must equal the number of rows for m2 for the multiplication
** to work. Returns a pointer to the matrix struct ret, with the proper
** dimensions.
*/

t_matrix	*matrix_mult(t_matrix *m1, t_matrix *m2, t_matrix *ret)
{
	int			var;

	if (m1->j != m2->i)
		return (NULL);
	if (!(ret->mat = (float*)ft_memalloc(sizeof(*ret->mat) * m1->i * m2->j)))
		return (NULL);
	ret->i = -1;
	while (++ret->i < m1->i)
	{
		ret->j = -1;
		while (++ret->j < m2->j)
		{
			var = -1;
			while (++var < m2->i)
				ret->mat[(ret->i * m2->j) + ret->j] +=
					m1->mat[(ret->i * m1->j) + var] *
					m2->mat[(var * m2->j) + ret->j];
		}
	}
	return (ret);
}

/*
** mx_square_mult will multiply two square matrices. Will return a float array
** with the matrix values.
*/

float		*mx_square_mult(float *m1, float *m2, int dim)
{
	float	*result;
	int		i;
	int		j;
	int		var;

	if (!(result = (float *)ft_memalloc(sizeof(*result) * dim * dim)))
		return (NULL);
	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
		{
			var = -1;
			while (++var < dim)
				result[(i * dim) + j] += m1[i * dim + var] * m2[var * dim + j];
		}
	}
	return (result);
}
