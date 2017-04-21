/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:42:49 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/20 17:22:14 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** returns a pointer to the last non whitespace character
*/

char	*skip_space_rev(char *line, int len)
{
	char	*tail;

	tail = NULL;
	if (line && len)
	{
		tail = line + (len - 1);
		while (ft_iswhitespace(*tail) && tail != line)
			tail--;
	}
	return (tail);
}
