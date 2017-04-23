/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:01:59 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/23 16:16:51 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** write_op will write the byte code to the output vector, and keep track of
** label_calls.
*/

int	write_op(const t_op *op, char *line, t_vec *output, t_vec *label_calls)
{
	ft_printf("op:%s line:%s\n", op->name_short, line);
	(void)op;
	(void)line;
	(void)output;
	(void)label_calls;
	return (0);
}
