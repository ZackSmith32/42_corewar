/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:36:04 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/20 20:46:26 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Scans multiple lines in order to complete the quote for the command string
*/

static int	complete_quotes(char *dst, size_t max, t_parseinfo *pi,
		size_t current_size)
{
	char	*line;
	char	*tail;
	ssize_t	len;

	while ((len = get_next_line(pi->fd, &line)) > 0)
	{
		pi->row++;
		ft_printf("row:%d\n", pi->row);///
		dst[current_size] = '\n';
		tail = skip_space_rev(line, len);
		pi->col = (tail - line) + 1;
		ft_printf("current_size:%zd max:%zu tail:%c\n", current_size + (tail - line), max, *tail);
		current_size += (tail - line) + 1;
		if (!ft_strchr(line, '"'))
			current_size = ft_strlcat(dst, line, max + 1);
		else if (*tail != '"')
			current_size = -6;
		else if (current_size <= max && !(current_size = 0))
			ft_strncat(dst, line, (tail - line));
		ft_strdel(&line);
		if (current_size > max || current_size <= 0)
			return (current_size > max ? -8 : current_size);
	}
	return (-1);
}

/*
** Finds the corresponding string for the command and copies it into the header.
*/

static int	read_quotes(char *dst, char *src, size_t max, t_parseinfo *pi)
{
	char	*head;
	size_t	current_size;

	head = skip_whitespaces(src);
	pi->col += (head - src) + 1;
	ft_printf("head:%c\n", *head);///
	if (*head != '"')
		return (-6);
	src = ft_strchr(head + 1, '"');
	if (src)
	{
		if ((size_t)(src - head) <= max)
			ft_strncpy(dst, head + 1, (src - head - 1));
		else
			return (-8);
	}
	else
	{
		if ((current_size = ft_strlcat(dst, head + 1, max + 1)) > max)
			return (-8);
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

	ft_printf("Reading commands:%.6s\n", line);///
	if (!ft_strncmp(line, COMMENT_CMD_STRING, info->comment_cmd_len))
	{
		line += info->comment_cmd_len;
		pi->col += info->comment_cmd_len;
		if ((ern = read_quotes(header->comment, line, COMMENT_LENGTH, pi)) ||
				info->commands_checked & 1)
			return (ern == -8 ? -9 : -6);
		info->commands_checked |= 1;
	}
	else if (!ft_strncmp(line, NAME_CMD_STRING, info->name_cmd_len))
	{
		ft_printf("reading name\n");///
		line += info->name_cmd_len;
		pi->col += info->name_cmd_len;
		if ((ern = read_quotes(header->prog_name, line, PROG_NAME_LENGTH, pi))
				|| info->commands_checked & 2)
			return (ern ? ern : -6);
		info->commands_checked |= 2;
	}
	return (0);
}

