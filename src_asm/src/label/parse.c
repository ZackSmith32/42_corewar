/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:52:37 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/22 17:58:15 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Parse_labels
**		Adds new label to the list if needed (does not delete if added).
*/

int	parse_label(char *cp, t_asm *as, int depth)
{
	char 	*label;
	int		ern;

	if (!(label = dup_label(&cp, &as->pi.col)))
		return (LEXICAL);
	if (*cp == LABEL_CHAR)
	{
		if (depth)
		{
			ft_strdel(&label);
			return (SYNTAX);
		}
		if ((ern = new_label(&as->labels, label, as->header.prog_size)))
			ft_strdel(&label);
		if (parse_line(cp + 1, as, depth + 1))
			return (1);
	}
/*	else
		parse_op(label, cp, as);*/
/*	ft_printf("label:%s\ncp:%c row:%d col:%d\n",
			label, *cp, as->pi.row, as->pi.col);*/
	return (0);
}
