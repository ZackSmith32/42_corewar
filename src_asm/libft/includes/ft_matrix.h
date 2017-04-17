/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:25:31 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/03 15:41:56 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

typedef struct	s_matrix
{
	float		*mat;
	int			i;
	int			j;
}				t_matrix;

t_matrix		*matrix_mult(t_matrix *m1, t_matrix *m2, t_matrix *ret);
float			*mx_square_mult(float *m1, float *m2, int dim);

/*
** Matrix creating functions for manipulating vectors
*/

float			*mx_id(int dim);
float			*mx_scale(float *sc, int len);
float			*mx_translate(float *tr, int len);
#endif
