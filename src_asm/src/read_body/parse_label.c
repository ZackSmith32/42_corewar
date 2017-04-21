/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:52:37 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/20 23:13:40 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Parse_labels
**	Determine if a new label needs to be added to the list
**	Call the appropriate function
*/

int	parse_label(char *cp, t_asm *as)
{
	char 	*label;
	int		ern;

	if (!(label = dup_label(&cp, &as->pi.col)))
		return (LEXICAL);
	if (*cp == LABEL_CHAR)
	{
		if ((ern = new_label(label, as)))
			ft_strdel(&label);
	}
	ft_printf("label:%s\ncp:%c row:%d col:%d\n",
			label, *cp, as->pi.row, as->pi.col);
	return (0);
}
