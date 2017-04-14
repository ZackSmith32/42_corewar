/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/05 13:44:18 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void		print_byte_in_hex(uint8_t byte)
{
	uint8_t	c;

	c = 0x0F & byte;
	byte = 0x0F & (byte >> 4);
	printf("first: %x\n", byte);
	printf("second: %x\n", c);
	printf("first: %d\n", byte);
	printf("second: %d\n", c);
	byte = byte > 9 ? byte - 9 + 'A': byte + '0';
	c = c > 9 ? c - 9 + 'A' : c + '0';
	printf("\nfirst: %c\n", byte);
	printf("second: %c\n", c);
	printf("first: %d\n", byte);
	printf("second: %d\n", c);
	write(1, &byte, 1);
	write(1, &c, 1);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
}

void		print_hex(void *loc, size_t size)
{
	uint8_t	*loc_conv;

	loc_conv = (uint8_t*)loc;
	while (size)
	{
		print_byte_in_hex(*loc_conv);
		loc_conv++;
		size--;
	}
}