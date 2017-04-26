/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_body.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:13:43 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 16:23:41 by kdavis           ###   ########.fr       */
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
		ern = parse_line(line, as, 0);
		ft_strdel(&line);
		if (ern)
			return (1);
	}
	if (ern == -1)
		return (print_error(1, NULL, 0));
	ft_strdel(&line);
	if (fill_labels(&as->labels, &as->opp.label_calls, &as->opp.output))
		return (1);
	as->header.prog_size = flip_uint32(as->opp.output.len);
	if (as->opp.output.len > CHAMP_MAX_SIZE)
		return (print_error(10, NULL, 0));
	return (0);
}
