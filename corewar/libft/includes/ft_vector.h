/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:16:20 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/15 16:43:06 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <ft_memory.h>
# include <string.h>
# include <stdint.h>

/*
** structure: s_vec
** void	*arr = array of elements
** size_t len = Current number of elements in array
** size_t total = Total number of elements an array can hald
** uint8_t size = Size in bytes of each element in the array
*/

typedef struct	s_vec
{
	void		*arr;
	size_t		len;
	size_t		total;
	uint8_t		size;
}				t_vec;

int				ft_initialize_vec(t_vec *vec, uint8_t sz, size_t t, size_t len);
int				ft_grow_vec(t_vec *self, size_t requested_bytes);
int				ft_vecapp(t_vec *self, void *src, size_t n);
#endif
