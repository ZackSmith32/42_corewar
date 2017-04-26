/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_body.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:13:43 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/25 20:25:37 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int	read_body(t_asm *as)
{
	char	*line;
	int		ern;

	while ((ern = get_next_line(as->pi.fd, &line)) >= 0)
	{
		as->pi.row++;
		as->pi.col = 1;
		ft_printf("row:%d\n", as->pi.row);///
		ern = parse_line(line, as, 0);
		ft_strdel(&line);
		if (ern)
			return (1);
	}
	if (ern == -1)
		return (print_error(1, NULL, 0, 0));
	ft_strdel(&line);
	as->header.prog_size = flip_uint32(as->opp.output.len);
	if (as->header.prog_size > CHAMP_MAX_SIZE)
		return (print_error(10, NULL, 0, 0));
	return (0);
}
