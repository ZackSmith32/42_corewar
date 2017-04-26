/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:31:09 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 13:41:59 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Parses the label and operation lines in the body of the input file
*/

int	parse_line(char *head, t_asm *as, int depth)
{
	char	*tail;
	char	*truncate;
	int		ern;

	ern = 0;
	tail = skip_whitespaces(head);
	truncate = ft_strchr(tail, COMMENT_CHAR);
	if (truncate)
		*truncate = '\0';
	as->pi.col += (tail - head);
	if (is_labelchar(*tail))
		ern = parse_label(tail, as, depth);
	else if (*tail != '\0')
		ern = LEXICAL;
	if (ern == 1)
		return (1);
	else if (ern)
		return (print_error(-ern, "BODY_ERROR", as->pi.row, as->pi.col));
	return (0);
}
