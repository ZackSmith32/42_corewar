/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_label_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:00:55 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/25 16:17:05 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** add_label_call creates a struct
** 
** op:		Holds information on the op being parsed
** op_prs:	Holds a vector for label calls as well as the output vector
** op_addr:	Location of the operation currently being parsed
** param:	Parameter being parsed
*/

int	add_label_call(const t_op *op, t_op_parse *op_prs, int op_addr, char *param)
{
	t_label_calls	call;
	char			*name;

	name = param + (*param == DIRECT_CHAR ? 2 : 1);
	call.size = *param == DIRECT_CHAR && !op->dir_as_ind ? DIR_SIZE : IND_SIZE;
	call.op_addr = op_addr;
	call.addr = op_prs->output.len;
	if (!(call.name = ft_strdup(name)))
		return (1);
	if (!(ft_vecapp(&op_prs->label_calls, &call, sizeof(t_label_calls))))
	{
		free(call.name);
		return (1);
	}
	ft_printf("\n\nname:%s\nsize:%d\nop_addr:%d\naddr:%d\n", name, call.size, call.op_addr, call.addr);
	return (0);
}
