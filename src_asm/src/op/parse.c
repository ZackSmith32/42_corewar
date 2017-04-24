/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 23:02:56 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/24 14:17:17 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Parse op is the function responsible for calling the appropriate operation
** par
*/

int	parse_op(char *label, char *line, t_asm *as)
{
	int	op_code;

/*	ft_printf("label:%s first 3 char:%.3s, row:%d col:%d\n",
			label, line, as->pi.row, as->pi.col);*/
	if (!(op_code = search_op(label)))
		return (print_error(6, "ILLEGAL_OP", as->pi.row, as->pi.col));
	if ((write_op(op_code, line, &as->output, &as->label_calls)))
		return (print_error(6, "OP_ERROR", as->pi.row, as->pi.col));
	return (0);
}
