/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 21:03:07 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/25 21:38:41 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Thought: Read in full file as string, then use strchr in place of get
** next line for moving through the lines.
**
** Pros: It will make name reading much easier
** Cons: It will probably make later portions tougher
*/

int	read_header(t_asm *as)
{
	char	*line;
	char	*cp;
	int		ern;

	as->header.magic = flip_uint32(COREWAR_EXEC_MAGIC);
	while ((ern = get_next_line(as->pi.fd, &line)) > 0)
	{
		as->pi.row++;
		cp = skip_whitespaces(line);
		as->pi.col = 1 + (cp - line);
//		ft_printf("row:%d col:%d\n", as->pi.row, as->pi.col);///
		if (*cp == COMMAND_CHAR)
			ern = read_command(&as->header, cp, &as->pi, &as->cmd_info);
		else if (*cp != COMMENT_CHAR && *cp != '\0')
			ern = LEXICAL;
//		ft_printf("ern:%d, cp:%c\n", ern, *cp);
		ft_strdel(&line);
		if (ern < 0)
			return (print_error(-ern, "HEADER_ERROR", as->pi.row, as->pi.col));
		else if (!(as->cmd_info.commands_checked ^ 0x3))
			return (0);
	}
	return (print_error(1, NULL, 0, 0));
}
