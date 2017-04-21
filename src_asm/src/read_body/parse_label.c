/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:52:37 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/20 22:09:39 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Parse_labels
*/

int	parse_labels(char *cp, t_asm *as)
{
	char *label;

	if (!(label = dup_label(cp, &as->pi)))
		return (LEXICAL);
}
