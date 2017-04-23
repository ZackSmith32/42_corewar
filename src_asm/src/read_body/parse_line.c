/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:31:09 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/22 13:45:13 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Parses the label and operation lines in the body of the input file
*/

int	parse_line(char	*head, t_asm *as, int depth)
{
	char	*tail;
	int		ern;

	ern = 0;
	tail = skip_whitespaces(head);
	as->pi.col += (tail - head);
/*	ft_printf("char:%c row:%d col:%d\n",*tail, as->pi.row,  as->pi.col);*/
	if (is_labelchar(*tail))
		ern = parse_label(tail, as, depth);
	else if (*tail != COMMENT_CHAR && *tail != '\0')
		ern = LEXICAL;
	if (ern == 1)
		return (1);
	else if (ern)
		return (print_error(-ern, "BODY_ERROR", as->pi.row, as->pi.col));
	return (0);
}
