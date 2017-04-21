/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_body.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:13:43 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/20 22:21:37 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int	read_body(t_asm *as)
{
	char	*line;
	char	*cp;
	int		ern;

	while ((ern = get_next_line(as->pi.fd, &line)) >= 0)
	{
		as->pi.row++;
		ft_printf("row:%d\n", as->pi.row);///
		cp = skip_whitespaces(line);
		as->pi.col = 1 + (cp - line);
		ft_printf("first char:%c\n", *cp);///
		if (is_labelchar(*cp))
			ern = -parse_label(cp, as);
		else if (*cp != COMMENT_CHAR && *cp != '\0')
			ern = LEXICAL;
		ft_strdel(&line);
		if (ern < 0)
			return (print_error(-ern, "BODY_ERROR", as->pi.row, as->pi.col));
	}
	if (ern == -1)
		return (print_error(1, NULL, 0, 0));
	ft_strdel(&line);
	return (0);
}
