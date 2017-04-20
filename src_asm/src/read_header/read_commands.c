/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:36:04 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/19 21:29:29 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	read_quotes(char *dst, char *src, size_t max_size, int *col)
{
	char	*head;

	head = skip_whitespaces(src);
	*col += (head - src);
	if (*head != '"')
		return (-6);
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
	size_t		len;

	len = ft_strlen(COMMENT_CMD_STRING);
	if (!ft_strncmp(line, COMMENT_CMD_STRING, info->comment_cmd_len))
	{
		line += info->comment_cmd_len;
		*col += info->comment_cmd_len;
		if (read_quotes(header->comment, line, COMMENT_LENGTH, col) ||
				info->commands_checked & 1)
			return (-6);
		info->commands_checked |= 1;
	}
	else if (!ft_strncmp(line, NAME_CMD_STRING, info->name_cmd_len))
	{
		line += info->name_cmd_len;
		*col += info->name_cmd_len;
		if (read_quotes(header->prog_name, line, PROG_NAME_LENGTH, col) ||
				info->commands_checked & 2)
			return (-6);
		info->commands_checked |= 2;
	}
	return (0);
}

