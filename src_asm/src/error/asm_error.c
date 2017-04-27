/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:21:16 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 16:31:06 by kdavis           ###   ########.fr       */
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
	"Syntax error at token [TOKEN][ROW:%03d] %s\n",
	"Lexical error at [ROW:%d]\n",
	"Name is too long\n",
	"Comment is too long\n",
	"Program size too big\n",
	"addr:%d label %s not found\n",
};

int			print_error(int ern, char *str, int row)
{
	if (ern < 0)
		ft_putendl_fd(str, 2);
	else
		ft_dprintf(2, g_error_message[ern], row, str);
	return (ern);
}

/*
** Flushes the label and label_call vector allocations
*/

static void	clear_labels(t_vec *label, int label_flag)
{
	t_label			*lbl;
	t_label_calls	*call;
	size_t			i;

	i = 0;
	while (i < label->len)
	{
		if (label_flag)
		{
			lbl = (t_label*)ft_vecindex(label, i);
			ft_strdel(&lbl->name);
		}
		else
		{
			call = (t_label_calls*)ft_vecindex(label, i);
			ft_strdel(&call->name);
		}
		i++;
	}
	ft_memdel(&label->arr);
}

/*
** reads through the rest of the file in order to delete any allocations
** leftover in gnl static variables.
*/

static void	flush_gnl(int fd)
{
	char	*flush;

	while (get_next_line(fd, &flush) >= 0)
		ft_strdel(&flush);
	ft_strdel(&flush);
}

/*
** Clean up function responsible for final output printing and cleaning
**	up all leftover allocations.
*/

int			asm_error(t_asm *master, int ern)
{
	clear_labels(&master->labels, 1);
	clear_labels(&master->opp.label_calls, 0);
	flush_gnl(master->pi.fd);
	ft_memdel(&master->opp.output.arr);
	if (ern == 0)
		ft_dprintf(1, g_error_message[ern], master->name);
	ft_strdel(&master->name);
	if (ern != 2)
		close(master->pi.fd);
	return (ern);
}
