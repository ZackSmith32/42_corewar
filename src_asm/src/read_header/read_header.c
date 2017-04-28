/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 21:03:07 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/28 13:42:51 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Reads the file until both the name and comment commands have been parsed
*/

int	read_header(t_asm *as)
{
	char	*line;
	char	*cp;
	int		ern;

	as->header.magic = flip_uint32(COREWAR_EXEC_MAGIC);
	while ((ern = get_next_line(as->pi.fd, &line)) >= 0)
	{
		as->pi.row++;
		cp = skip_whitespaces(line);
		if (*cp == COMMAND_CHAR)
			ern = read_command(&as->header, cp, &as->pi, &as->cmd_info);
		else if (*cp != COMMENT_CHAR && *cp != '\0' && *cp != ';')
			ern = LEXICAL;
		ft_strdel(&line);
		if (ern < 0)
			return (print_error(-ern, "HEADER_ERROR", as->pi.row));
		else if (!(as->cmd_info.commands_checked ^ 0x3))
			return (0);
	}
	return (print_error(1, NULL, 0));
}
