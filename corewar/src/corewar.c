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

int32_t				g_error = 0;
static char const	*g_error_msg[] = {
	"no error",
	"generic error",
	"file format issue"
	"flag format issue"
};

static void			handle_error(struct s_game *game)
{

	free_game(game);
	if (errno)
		perror("corewar: ERROR");
	else
	{
		ft_dprintf(STDERR_FILENO, "corewar: ERROR: %s\n", g_error_msg[g_error]);
	}
	exit(1);
}

int					main(int argc, char **argv)
{
	struct s_game	game;
	char			*champions[MAX_PLAYERS + 1];

	if (-1 == flags_get(&argc, &argv, (char ***)&champions))
	{
		handle_error(NULL);
	}
	if (-1 == game_init((const char ***)&champions, &game))
	{
		handle_error(&game);
	}
	while (game.winner == NULL)
	{
		if (-1 == game_step(&game) || -1 == game_print(&game))
		{
			handle_error(&game);
		}
		ft_printf("hello world\n");
	}
	free_game(&game);
	return (0);
}
