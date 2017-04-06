/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/03/04 18:52:04 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	load_champion(char const *file, void *loc, struct s_champ *champ)
{
	header_t	header;
	int			fd;
	ssize_t		size;

	if (-1 == (fd = open(file, O_RDONLY)))
		return (-1);
	if (-1 == (size = read(fd, &header, sizeof(header))))
		return (-1);
	if (size != sizeof(header))
	{
		g_error = 2;
		return (-1);
	}
	if (-1 == (size = read(fd, loc, header.prog_size)))
		return (-1);
	if (size != head.prog_size)
	{
		g_error = 2;
		return (-1);
	}
	if (-1 == close(fd))
		return (-1);
	champ->prog_name = header.prog_name;
	champ->comment = header.comment;
	champ->alive = true;
	return (0);
}

int			add_process(t_vec *processes, void *loc)
{
	//TODO: kyle, how do i vector??
	(void)(process);
	(void)(loc);
	return (0);
}

int			game_init(char const **champs, struct s_game *game)
{
	int		champ_count;
	size_t	offset;
	size_t	start_loc;
	int		i;

	ft_bzero(game, sizeof(*game));
	champ_count = 0;
	while (champs[champ_count])
		champ_count++;
	offset = MEM_SIZE / champ_count;
	start_loc = 0;
	i = 0;
	while (i < champ_count)
	{
		if (-1 == load_champion(champs[i], game->arena + start_loc, &(game->champs[i])))
			return (-1);
		if (-1 == add_process(&game->processes, game->arena + start_loc))
			return (-1);
		i++;
		start_loc += offset;
	}
	return (0);
}