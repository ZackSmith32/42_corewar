/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/05 13:46:56 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <op.h>
#include <errno.h>
#include <libft.h>
#include <unistd.h>

//TODO: priotity one: get everything to compile
//TODO: what's up with t_op? Figure out what is inside of t_op

//NOTE: program breaks after first loop
//NOTE: bypassed flags_get with function below, flags_get isnt in the makefile for the moment as it does not compile

int32_t				g_error = 0;
struct s_flag			g_flags;
static char const	*g_error_msg[] = {
	"no error",
	"generic error",
	"file format issue"
	"flag format issue"
};

static void			handle_error(struct s_game *game)
{
	(void)(game); //is there anything that needs to be free'd in game?
	if (errno)
		perror("corewar: ERROR");
	else
	{
		ft_dprintf(STDERR_FILENO, "corewar: ERROR: %s\n", g_error_msg[g_error]);
	}
	exit(1);
}

/*
int					flags_get(int *ac, char ***av, char **champ)
{
	(void)(ac);
	champ[0] = (*av)[1];
	champ[1] = NULL;
	return (0);
}
*/

int					main(int argc, char **argv)
{
	struct s_game	game;
	char			*champions[MAX_PLAYERS + 1];

	size_t	i;

	i = 15;
	if (-1 == flags_get(&argc, &argv, champions))
	{
		handle_error(NULL);
	}
	if (-1 == game_init(champions, &game))
	{
		handle_error(&game);
	}
	while (game.game_over == false)
	{
		if (-1 == game_print(&game) || -1 == game_step(&game))
		{
			handle_error(&game);
		}
		i--;
		if (i == 0)
			break ;
	}
	if (-1 == game_print(&game))
		handle_error(&game);
	free_game(&game);
	return (0);
}
