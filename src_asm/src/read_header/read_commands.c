/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:36:04 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/19 20:40:20 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	read_quotes(char *dst, char *src, size_t max_size)
{
}

/*
** Look for the corresponding commands that the input may call.
** known commands:
** 		.name: Prefaces the name of the champion
**		.comment: Prefaces the comment for the champion
*/

int	read_commands(header_t *header, char *line, t_cmdinfo *info)
{
	size_t		len;

	len = ft_strlen(COMMENT_CMD_STRING);
	if (!ft_strncmp(line, COMMENT_CMD_STRING, len))
	{
		if (info->commands_checked & 1)
			return (-6);
		info->commands_checked |= 1;
	}
	else if (!ft_strncmp(line, NAME_CMD_STRING, (len = ft_strlen(NAME_CMD_STRING))))
	{
		if (info->commands_checked & 2)
			return (-6);
		info->commands_checked |= 2;
	}
}

