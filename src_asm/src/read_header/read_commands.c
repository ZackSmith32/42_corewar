/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:36:04 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 13:18:11 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Scans multiple lines in order to complete the quote for the command string
*/

/*
** have the end be strchr '"' then skip_whitespaces after the quote.
*/

static int	complete_quotes(char *dst, size_t max, t_parseinfo *pi,
		size_t current_size)
{
	char	*line;
	char	*end;
	char	*tail;
	int		ern;

	while (get_next_line(pi->fd, &line) > 0)
	{
		pi->row++;
		dst[current_size] = '\n';
		tail = ft_strchr(line, '"');
		pi->col = (tail - line) + 1;
		current_size += (tail - line) + 1;
		if (!tail)
			current_size = ft_strlcat(dst, line, max + 1);
		else if (*(end = skip_whitespaces(tail + 1)) != COMMENT_CHAR &&
				*end != '\0')
			ern = LEXICAL;
		else if (current_size <= max && !(ern = 0))
			ft_strncat(dst, line, (tail - line));
		ft_strdel(&line);
		if (current_size > max || ern == LEXICAL || ern == 0)
			return (current_size > max ? NAME_LONG : ern);
	}
	return (-1);
}

/*
** Finds the corresponding string for the command and copies it into the header.
*/

static int	read_quotes(char *dst, char *src, size_t max, t_parseinfo *pi)
{
	char	*hd;
	size_t	current_size;

	hd = skip_whitespaces(src);
	pi->col += (hd - src) + 1;
	if (*hd != '"')
		return (SYNTAX);
	src = ft_strchr(hd + 1, '"');
	if (src)
	{
		pi->col += (src - hd);
		if ((size_t)(src - hd) <= max)
			ft_strncpy(dst, hd + 1, (src - hd - 1));
		else
			return (NAME_LONG);
		if (*(hd = skip_whitespaces(src + 1)) != COMMENT_CHAR && *hd != '\0')
			return (LEXICAL);
	}
	else
	{
		if ((current_size = ft_strlcat(dst, hd + 1, max + 1)) > max)
			return (NAME_LONG);
		return (complete_quotes(dst, max, pi, current_size));
	}
	return (0);
}

/*
** Look for the corresponding commands that the input may call.
** known commands:
** 		.name: Prefaces the name of the champion
**		.comment: Prefaces the comment for the champion
*/

int	read_command(header_t *header, char *line, t_parseinfo *pi, t_cmdinfo *info)
{
	int			ern;

//	ft_printf("Reading commands:%.6s\n", line);///
	if (!ft_strncmp(line, COMMENT_CMD_STRING, info->comment_cmd_len))
	{
		line += info->comment_cmd_len;
		pi->col += info->comment_cmd_len;
		if ((ern = read_quotes(header->comment, line, COMMENT_LENGTH, pi)) ||
				info->commands_checked & 1)
			return (ern == NAME_LONG ? COMM_LONG : LEXICAL);
		info->commands_checked |= 1;
	}
	else if (!ft_strncmp(line, NAME_CMD_STRING, info->name_cmd_len))
	{
//		ft_printf("reading name\n");///
		line += info->name_cmd_len;
		pi->col += info->name_cmd_len;
		if ((ern = read_quotes(header->prog_name, line, PROG_NAME_LENGTH, pi))
				|| info->commands_checked & 2)
			return (ern ? ern : LEXICAL);
		info->commands_checked |= 2;
	}
	return (0);
}

