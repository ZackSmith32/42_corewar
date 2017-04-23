/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 14:13:32 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/22 14:20:06 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Searches a the vector for the corresponding label and returns a pointer
** if one is found.
*/

t_label	*search_label(char *key, t_vec *labels)
{
	t_label *current;
	size_t	i;

	i = 0;
	while (i < labels->len)
	{
		current = ft_vecindex(labels, i);
		ft_printf("current->name:%s\n", current->name);///
		if (ft_strcmp(key, current->name) == 0)
			return (current);
		i++;
	}
	return (NULL);
}
