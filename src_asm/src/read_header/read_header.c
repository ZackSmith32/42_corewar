/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 21:03:07 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/20 12:01:51 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*int	read_name(t_asm *master)
{
	size_t	name_len;

	name_len = ft_strlen(NAME_CMD_STRING);
	if ((next_token(&master->cp) == -1) ||
			ft_strncmp(master->cp, NAME_CMD_STRING, name_len))
		return (7);
	master->cp += name_len;
	if (next_token(&master->cp))
		return (7);
	ft_printf("%.5s\n", master->cp);
	return (0);
}

int	read_header(t_asm *master)
{
	int	ern;
	size_t	len;

	master->header.magic = flip_uint32(COREWAR_EXEC_MAGIC);
	if ((ern = read_name(master)))
		return (ern);
	end = ft_memccpy(m->header.prog_name, m->file.arr, '"', PROG_NAME_LENGTH);
	if (end)
		*(((char*)end) - 1) = 0;
	read_name(header->prog_name, fd);
	read_comment(header->comment, fd);
	return (0);
}*/

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

	while ((ern = get_next_line(as->pi.fd, &line)) > 0)
	{
		as->pi.col = 1;
		cp = skip_whitespaces(line);
		if (*cp == COMMAND_CHAR)
			ern = read_command(&as->header, cp, &as->pi, &as->cmd_info);
		else if (*cp != COMMENT_CHAR && *cp != '\0')
			ern = -7;
		ft_strdel(&line);
		if (ern < 0)
			return (print_error(-ern, "HEADER_ERROR", as->pi.row, as->pi.col));
		as->pi.row++;
	}
	if (ern == -1)
		return (print_error(1, NULL, 0, 0));
	ft_strdel(&line);
	return (0);
}
