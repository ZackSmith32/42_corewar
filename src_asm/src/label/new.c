/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 22:48:30 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 13:31:11 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** new_label takes a label and adds it to a list of labels if it is not there
** already. Sets the labels name and address.
** Requires that the label vector was already initialized.
*/

int	new_label(t_vec *labels, char *name, int address)
{
	t_label	*current;
	t_label	new;

	if (!(labels->arr))
		return (-1);
	if ((current = search_label(name, labels)))
	{
		if (current->address == -1)
			current->address = address;
		return (1);
	}
	if (!(new.name = ft_strdup(name)))
		return (-1);
	new.address = address;
	if (!(ft_vecapp(labels, &new, sizeof(new))))
		return (-1);
	return (0);
}
