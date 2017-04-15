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
		| ((n << 8 ) & 0xFF0000)
		| (n << 24)
	);
}

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
	header.prog_size = fix_end(header.prog_size);
	if (-1 == (size = read(fd, loc, header.prog_size)))
		return (-1);
	if (size != header.prog_size)
	{
		g_error = 2;
		return (-1);
	}
	if (-1 == close(fd))
		return (-1);
	ft_memmove(champ->prog_name, header.prog_name, sizeof(header.prog_name));
	ft_memmove(champ->comment, header.comment, sizeof(header.comment));
	champ->alive = true;
	return (0);
}

//TODO: init op_code and countdown
static int	add_process(t_list **processes, void *pc)
{
	struct s_process	*p;

	if (NULL == (p = (struct s_process*)malloc(sizeof(*p))))
		return (-1);
	ft_bzero(p, sizeof(*p));
	p->registors[0] = 1;//TODO: SET THIS TO BE THE RIGHT ID
	p->pc = pc;
	lstadd(processes, lstnew((void*)p));
	return (0);
}

int			game_init(char **champs, struct s_game *game)
{
	int			champ_count;
	size_t		offset;
	size_t		start_loc;
	int			i;

	ft_bzero(game, sizeof(*game));
	champ_count = 0;
	while (champs[champ_count])
		champ_count++;
	if (champ_count)
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