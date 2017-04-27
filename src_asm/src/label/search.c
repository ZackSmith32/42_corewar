/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 14:13:32 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 13:30:53 by kdavis           ###   ########.fr       */
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
		if (ft_strcmp(key, current->name) == 0)
			return (current);
		i++;
	}
	return (NULL);
}
