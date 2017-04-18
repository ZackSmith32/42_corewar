/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_switch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:37:08 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/17 15:25:54 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Endian flipping functions for changing input into big endian
*/

uint8_t		flip_uint8(uint8_t nbr)
{
	return ((0xFF & (nbr >> 8)) | (0xFF00 & (nbr << 8)));
}

uint32_t	flip_uint32(uint32_t nbr)
{
	return (((nbr >> 24) & 0xFF)
			| ((nbr >> 8) & 0xFF00)
			| ((nbr << 8) & 0xFF0000)
			| ((nbr << 24) & 0xFF000000));
}

uint32_t	flip_uint64(uint64_t nbr)
{
	return (((nbr >> 56) & 0xFFULL)
			| ((nbr >> 40) & (0xFFULL << 8))
			| ((nbr >> 24) & (0xFFULL << 16))
			| ((nbr >> 8) & (0xFFULL << 24))
			| ((nbr << 8) & (0xFFULL << 32))
			| ((nbr << 24) & (0xFFULL << 40))
			| ((nbr << 40) & (0xFFULL << 48))
			| (nbr << 56));
}
