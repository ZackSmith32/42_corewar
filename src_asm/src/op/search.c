/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:05:52 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/22 18:15:48 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** search_op will search for the 'key' operation in g_op_tab
*/

const t_op	*search_op(char *name)
{
	int	i;

	i = 1;
	while (g_op_tab[i].name_short)
	{
		if (ft_strcmp(name, g_op_tab[i].name_short) == 0) 
			return (g_op_tab + i);
		i++;
	}
	return (NULL);
}
