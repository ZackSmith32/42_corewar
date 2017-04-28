/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:31:09 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/28 13:51:46 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Sets the first instance of 'c' in the line to be a null terminating 0
*/

static void	truncate_at(char *str, char c)
{
	char *truncate;

	truncate = ft_strchr(str, c);
	if (truncate)
		*truncate = '\0';
}

/*
** Parses the label and operation lines in the body of the input file
*/

int	parse_line(char *head, t_asm *as, int depth)
{
	char	*tail;
	int		ern;

	ern = 0;
	tail = skip_whitespaces(head);
	truncate_at(tail, COMMENT_CHAR);
	truncate_at(tail, ';');
	if (is_labelchar(*tail))
		ern = parse_label(tail, as, depth);
	else if (*tail != '\0')
		ern = LEXICAL;
	if (ern == 1)
		return (1);
	else if (ern)
		return (print_error(-ern, "BODY_ERROR", as->pi.row));
	return (0);
}
