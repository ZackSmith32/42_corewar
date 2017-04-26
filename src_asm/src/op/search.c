/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:05:52 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 13:34:57 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** search_op will search for the 'key' operation in g_op_tab
*/

int	search_op(char *name)
{
	int	op_code;

	op_code = 1;
	while (g_op_tab[op_code].name_short)
	{
		if (ft_strcmp(name, g_op_tab[op_code].name_short) == 0)
			return (op_code);
		op_code++;
	}
	return (0);
}
