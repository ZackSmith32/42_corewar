/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 22:48:30 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/21 14:01:29 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** new_label takes a label and adds it to a list of labels if it is not there
** already. Sets the labels name and address.
*/

int	new_label(t_vec *labels, char *name, int address)
{
	t_label	*current;
	t_label	new;
	size_t	i;

	if (!(labels->arr))
		if (!(ft_initialize_vec(labels, sizeof(t_label), 10, 0)))
			return (-1);;
	i = 0;
	while (i < labels->len)
	{
		current = ft_vecindex(labels, i);
		ft_printf("current->name:%s\n", current->name);///
		if (ft_strcmp(name, current->name) == 0)
			return (1);
		i++;
	}
	new.name = name;
	new.address = address;
	if (!(ft_vecapp(labels, &new, sizeof(new))))
		return (-1);
	return (0);
}
