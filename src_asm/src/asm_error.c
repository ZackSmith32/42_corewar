/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:21:16 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/17 20:52:58 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static const char	*g_error_message[] =
{
	"Writing output program to %s.cor",
	"error allocating memory",
	"error opening file",
	"error reading or closing file",
	"Syntax error at token [%s][%03d:%03d] %s"
};

static int	find_position(char *file, char *cursor, int *col)
{
	char	*next;
	int		row;

	row = 1;
	if(!(file))
		return (0);
	next = ft_strchr(file, '\n');
	while (next && next < cursor)
	{
		file = next;
		next = ft_strchr(file, '\n');
	}
	if (cursor && file)
		*col = cursor - file;
	return (row);
}

int	asm_error(t_asm *master, int ern)
{
	int	row;
	int	col;

	col = 0;
	row = find_position((char*)master->file.arr, master->cp, &col);
	if (ern > 0)
		ft_dprintf(2, g_error_message[ern], "TOKEN", row, col, "token"); 
	else
		ft_dprintf(1, g_error_message[ern], ); 
	ft_memdel(&master->file.arr);
	if (fd != 0)
		close(fd);
	return(ern);
}
