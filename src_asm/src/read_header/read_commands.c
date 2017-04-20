/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:36:04 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/19 22:35:18 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	read_quotes(char *dst, char *src, size_t max_size, int *col)
{
	char	*head;

	head = skip_whitespaces(src);
	*col += (head - src) + 1;
	ft_printf("head:%c\n", *head);
	if (*head != '"')
		return (-6);
	src = ft_strchr(head + 1, '"');
	if (src)
	{
		if ((size_t)(src - head) <= max_size)
			ft_strncpy(dst, head + 1, (src - head - 1));
		else
			return (-8);
	}
	return (0);
	(void)dst;
	(void)max_size;
}

/*
** Look for the corresponding commands that the input may call.
** known commands:
** 		.name: Prefaces the name of the champion
**		.comment: Prefaces the comment for the champion
*/

int	read_commands(header_t *header, char *line, int *col, t_cmdinfo *info)
{
	int			ern;

	ft_printf("Reading commands:%.6s\n", line);///
	if (!ft_strncmp(line, COMMENT_CMD_STRING, info->comment_cmd_len))
	{
		line += info->comment_cmd_len;
		*col += info->comment_cmd_len;
		if ((ern = read_quotes(header->comment, line, COMMENT_LENGTH, col)) ||
				info->commands_checked & 1)
			return (ern == -8 ? -9 : -6);
		info->commands_checked |= 1;
	}
	else if (!ft_strncmp(line, NAME_CMD_STRING, info->name_cmd_len))
	{
		ft_printf("reading name\n");///
		line += info->name_cmd_len;
		*col += info->name_cmd_len;
		if ((ern = read_quotes(header->prog_name, line, PROG_NAME_LENGTH, col))
				|| info->commands_checked & 2)
			return (ern ? ern : -6);
		info->commands_checked |= 2;
	}
	return (0);
}

