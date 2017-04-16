/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:15:14 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/15 12:54:56 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Steps to assembling:
**
** 1. Open and read file.
**
** 2. fill out header struct.
**		(Assign magic, Read program name and comment)
**			Calculate prog_size as you go.
**
** 3. Have an array of function pointers for translating individual operations
*/

int	g_error = 0;

static int	read_header(int fd, struct header_s *header)
{
}

int	main(int argc, char **argv)
{
	struct header_s	header;
	int				fd;

	if (argc != 2)
		return (ft_printf("Usage:./asm champion.s\n"));
	if ((fd = open(argv[2], O_RDONLY)) == -1)
		asm_error(1, 0);
	ft_bzero(&header, sizeof(header));
	header.magic = COREWAR_EXEC_MAGIC;
	return (0);
}
