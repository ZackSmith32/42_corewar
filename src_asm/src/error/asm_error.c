/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:21:16 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/22 18:18:42 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static const char	*g_error_message[] =
{
	"Writing output program to %s\n",				///0
	"error allocating memory\n",					///1
	"error opening file\n",							///2
	"error closing file\n",							///3
	"error reading file\n",							///4
	"error writing to file\n",						///5
	"Syntax error at token [TOKEN][%03d:%03d] %s\n",///6
	"Lexical error at [%d:%d]\n",					///7
	"Name is too long\n",							///8
	"Comment is too long\n",						///9
};
/*
static int	find_position(char *file, char *cursor, int *col)
{
	char	*next;
	int		row;

	if(!(file))
		return (0);
	next = ft_strchr(file, '\n');
	row = 0;
	while (next && next < cursor)
	{
		file = next;
		next = ft_strchr(file, '\n');
		if (next)
			next++;
		row++;
	}
	if (cursor && file)
		*col = (cursor - file) + 1;
	return (row ? row : 1);
}
*/
int	print_error(int ern, char *str, int row, int col)
{
	if (ern < 0)
		ft_putendl_fd(str, 2); 
	else
		ft_dprintf(2, g_error_message[ern], row, col, str); 
	return (ern);
}

void	clear_labels(t_vec *label)
{
	t_label *current;
	size_t	i;

	i = 0;
	while (i < label->len)
	{
		current = ft_vecindex(label, i);
		ft_memdel((void*)&current->name);
		i++;
	}
	ft_memdel(&label->arr);
}

int	asm_error(t_asm *master, int ern)
{
	clear_labels(&master->labels);
	clear_labels(&master->label_calls);
	ft_memdel(&master->output.arr);
	if (ern == 0)
		ft_dprintf(1, g_error_message[ern], master->name); 
	if (ern != 2)
		close(master->pi.fd);
	return(ern);
}
