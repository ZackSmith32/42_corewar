/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 23:02:56 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/22 17:42:49 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Parse op is the function responsible for calling the appropriate operation
** par
*/

int	parse_op(char *label, char *line, t_asm *as)
{
	t_op		*operation;

	if (!(operation = search_op(label)))
		return (print_error(6, "ILLEGAL_OP", as->pi.row, as->pi.col));
	if (!(write_op(operation, line, &as->labels, &label->calls)))
		return (print_error(6, "OP_ERROR", as->pi.row, as->pi.col));
}
