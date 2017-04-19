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

static unsigned int		fix_end(unsigned int n)
{
	return (
		((n >> 24) & 0xFF)
		| ((n >> 8) & 0xFF00)
		| ((n << 8) & 0xFF0000)
		| (n << 24));
}

static int				load_champion(char const *file,
							void *loc, struct s_champ *champ)
{
	header_t	header;
	int			fd;
	ssize_t		size;

	if (-1 == (fd = open(file, O_RDONLY))
		|| -1 == (size = read(fd, &header, sizeof(header))))
		return (-1);
	if (size != sizeof(header))
	{
		g_error = 2;
		return (-1);
	}
	header.prog_size = fix_end(header.prog_size);
	if (-1 == (size = read(fd, loc, header.prog_size))
		|| size != header.prog_size)
	{
		g_error = 2;
		return (-1);
	}
	if (-1 == close(fd))
		return (-1);
	ft_memmove(champ->prog_name, header.prog_name, sizeof(header.prog_name));
	ft_memmove(champ->comment, header.comment, sizeof(header.comment));
	return (0);
}

static int				add_process(t_list **processes, void *pc,
							unsigned short live)
{
	struct s_process	*p;

	if (NULL == (p = (struct s_process*)malloc(sizeof(*p))))
		return (-1);
	ft_bzero(p, sizeof(*p));
	p->registors[0] = live;
	p->pc = pc;
	p->countdown = 1;
	lstpush(processes, lstnew((void*)p));
	return (0);
}

static int				add_champs_processes(char **champs, struct s_game *game)
{
	size_t		offset;
	uint8_t		*start_loc;
	int			champ_index;
	int			i;

	offset = MEM_SIZE / game->champ_count;
	start_loc = game->arena;
	i = 0;
	champ_index = 0;
	while (i < MAX_PLAYERS)
	{
		if (champs[i])
		{
			if (-1 == load_champion(champs[i], start_loc,
					game->champs + champ_index)
				|| -1 == add_process(&game->processes, start_loc,
					~(unsigned short)champ_index))
				return (-1);
			champ_index++;
		}
		i++;
		start_loc += offset;
	}
	return (0);
}

int						game_init(char **champs, struct s_game *game)
{
	int			champ_count;
	int			i;

	champ_count = 0;
	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (champs[i])
			champ_count++;
		i++;
	}
	if (champ_count == 0)
	{
		g_error = 4;
		return (-1);
	}
	ft_bzero(game, sizeof(*game));
	game->champ_count = champ_count;
	game->cycles_to_death = CYCLE_TO_DIE;
	if (-1 == add_champs_processes(champs, game))
		return (-1);
	return (0);
}
