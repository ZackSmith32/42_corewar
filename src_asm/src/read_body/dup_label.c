/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:35:19 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/20 20:31:38 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Creates a duplicate of the label
*/

char	*dup_label(char	*src, t_parseinfo *pi)
{
	char *end;

	end = src;
	while (is_labelchar(*end))
		end++;
	pi->col += (end - src);
	ft_printf("char:%c\n", *end);///
	if (!ft_iswhitespace(*end) && *end != LABEL_CHAR && *end != SEPARATOR_CHAR
			&& *end != COMMENT_CHAR)
		return (NULL);
	return (ft_strndup(src, (end - src)));
}
