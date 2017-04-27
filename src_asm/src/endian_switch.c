/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_switch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:37:08 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 13:22:29 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Endian flipping functions for changing input into big endian
*/

uint32_t	flip_uint32(uint32_t nbr)
{
	return (((nbr >> 24) & 0xFF)
			| ((nbr >> 8) & 0xFF00)
			| ((nbr << 8) & 0xFF0000)
			| ((nbr << 24) & 0xFF000000));
}
