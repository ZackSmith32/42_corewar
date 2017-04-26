/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:21:16 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/25 22:27:22 by kdavis           ###   ########.fr       */
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
	"Program size too big\n",						///10
	"op addr:%d label addr:%d label %s not found\n",
};

int	print_error(int ern, char *str, int row, int col)
{
	if (ern < 0)
		ft_putendl_fd(str, 2); 
	else
		ft_dprintf(2, g_error_message[ern], row, col, str); 
	return (ern);
}

static void	clear_labels(t_vec *label, int label_flag)
{
	t_label			*lbl;
	t_label_calls	*call;
	size_t	i;

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

int	asm_error(t_asm *master, int ern)
{
	clear_labels(&master->labels, 1);
	clear_labels(&master->opp.label_calls, 0);
	ft_memdel(&master->opp.output.arr);
	if (ern == 0)
		ft_dprintf(1, g_error_message[ern], master->name); 
	ft_strdel(&master->name);
	if (ern != 2)
		close(master->pi.fd);
	return(ern);
}
