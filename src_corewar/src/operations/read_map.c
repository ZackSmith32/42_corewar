/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:07:59 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/13 11:49:41 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	read_vm(uint8_t *ptr, size_t size, uint8_t *ret)
{
	size_t	end;
	size_t	start;

	end = size;
	start = 0;
	while (end > 0)
	{
		end--;
		ret[start] = ptr[end];
		start++;
	}
}
