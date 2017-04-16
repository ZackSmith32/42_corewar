/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:21:45 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/04 17:30:29 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

/*
** ft_vec_foreach takes in a function pointer and applies that function to
** every element in the array.
*/

int	ft_vec_foreach(t_vec *self, int (f)(void*))
{
	void	*element;
	size_t	i;

	i = 0;
	while ((element = ft_vecindex(self, i)))
	{
		if (!f(element))
			return (0);
		i++;
	}
	return (1);
}
