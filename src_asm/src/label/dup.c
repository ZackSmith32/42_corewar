/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:35:19 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 13:30:02 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Creates a duplicate of the label
*/

char	*dup_label(char **src, int *col)
{
	char	*end;
	char	*ret;

	end = *src;
	while (is_labelchar(*end))
		end++;
	*col += (end - *src);
	if (!ft_iswhitespace(*end) && *end != LABEL_CHAR && *end != SEPARATOR_CHAR
			&& *end != COMMENT_CHAR && *end != DIRECT_CHAR)
		return (NULL);
	ret = ft_strndup(*src, (end - *src));
	*src = end;
	return (ret);
}
