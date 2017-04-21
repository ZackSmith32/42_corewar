/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:52:37 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/20 22:29:24 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Parse_labels
*/

int	parse_label(char *cp, t_asm *as)
{
	char *label;

	if (!(label = dup_label(&cp, &as->pi.col)))
		return (LEXICAL);
	ft_printf("label:%s\ncp:%c row:%d col:%d\n",
			label, *cp, as->pi.row, as->pi.col);
	return (0);
}
