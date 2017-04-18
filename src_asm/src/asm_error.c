/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:21:16 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/17 22:09:48 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static const char	*g_error_message[] =
{
	"Writing output program to %s\n",
	"error allocating memory\n",
	"error opening file\n",
	"error closing file\n",
	"error reading file\n",
	"error writing to file\n",
	"Syntax error at token [%s][%03d:%03d] %s\n"
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
		ft_dprintf(1, g_error_message[ern], master->name); 
	ft_memdel(&master->file.arr);
	return(ern);
}
