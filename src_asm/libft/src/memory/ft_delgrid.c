/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delgrid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:25:27 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/22 15:34:10 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

void	ft_delgrid(void ***grid)
{
	size_t	i;

	i = 0;
	if (!grid)
		return ;
	while (*(*grid + i))
	{
		ft_memdel(*grid + i);
		i++;
	}
	ft_memdel((void**)grid);
}
