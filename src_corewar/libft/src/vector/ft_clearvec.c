/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearvec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:52:07 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/18 14:55:34 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

/*
** ft_clearvec will zero out the array in the vector and reset the length to 0
*/

void	ft_clearvec(t_vec *self)
{
	ft_bzero(self->arr, self->len * self->size);
	self->len = 0;
}
