/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vindex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:10:19 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/04 17:17:33 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

/*
** ft_vindex returns the address at the position of the requested index in the
** array
*/

void	*ft_vecindex(t_vec *self, size_t idx)
{
	if (idx >= self->len)
		return (NULL);
	return (self->arr + (idx * self->size));
}
