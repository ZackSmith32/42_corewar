/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 23:02:56 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/25 21:20:02 by kdavis           ###   ########.fr       */
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

	if (!(op_code = search_op(label)))
		return (print_error(6, "ILLEGAL_OP", as->pi.row, as->pi.col));
	if ((write_op(op_code, line, &as->opp)))
		return (print_error(6, "PARAM_ERROR", as->pi.row, as->pi.col));
	return (0);
}
