/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_vec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:30:37 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/15 16:43:41 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

/*
** ft_initialize_vec takes in a vector and initializes all three portions.
** the size variable indicates the size of the vector (ie. char, int, etc..)
** the total variable indicates the number of elements of a given type to make
** space for.
*/

int	ft_initialize_vec(t_vec *vec, uint8_t size, size_t total, size_t len)
{
	if (!(vec->arr = ft_memalloc(size * total)))
		return (0);
	vec->size = size;
	vec->total = total;
	vec->len = len;
	return (1);
}
