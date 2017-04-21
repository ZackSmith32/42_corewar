/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_body.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:13:43 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/20 18:51:43 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int	read_body(t_asm *as)
{
	char	*line;
	char	*cp;
	int		ern;

	while ((ern = get_next_line(as->pi.fd, &line)) > 0)
	{
		cp = skip_whitespaces(line);
		as->pi.col = 1 + (cp - line);
		ft_strdel(&line);
	}
	if (ern == -1)
		return (print_error(1, NULL, 0, 0));
	ft_strdel(&line);
	return (0);
}
