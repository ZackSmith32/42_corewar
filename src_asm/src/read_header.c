/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 21:03:07 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/18 14:33:04 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int	read_name(t_asm *master)
{
	if (!(master->cp = next_token(master->file.arr)) ||
			ft_strncmp(master->cp, ".name", 5))
		return (7);
	ft_printf("%.5s\n", master->cp);
	return (0);
}

int	read_header(t_asm *master)
{
	int	ern;
/*	size_t	len;*/

	master->header.magic = flip_uint32(COREWAR_EXEC_MAGIC);
	if ((ern = read_name(master)))
		return (ern);
/*	end = ft_memccpy(m->header.prog_name, m->file.arr, '"', PROG_NAME_LENGTH);
	if (end)
		*(((char*)end) - 1) = 0;*/
/*	read_name(header->prog_name, fd);
	read_comment(header->comment, fd);*/
	return (0);
}
