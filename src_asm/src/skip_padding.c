/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:21:16 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/18 15:51:04 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Skips through white spaces and comments to acess the next token. Also keeps
** track of the number of new lines it goes through to access the next non
** padded area.
*/

int	next_token(char **cp)
{
	char	*tail;
	int		nl;

	tail = *cp;
	nl = 0;
	while (ft_iswhitespace(*tail) || *tail == '#')
	{
		if (*tail == '#')
			if(!(tail = ft_strchr(tail, '\n')))
				return (-1);
		if (*tail == '\n')
			nl++;
		tail++;
	}
	*cp = NULL;
	return (nl);
}
