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

/*
** TODO: validate with valgrind
** NOTE: program breaks after first loop
** NOTE: bypassed parse_args with function below, parse_args isnt in the
**        makefile for the moment as it does not compile
*/

int32_t				g_error = 0;
struct s_flag			g_flags;
static char const	*g_error_msg[] = {
	"no error",
	"generic error",
	"file format issue",
	"flag format issue",
	"no champs found"
};

static void			handle_error(struct s_game *game)
{
	if (game)
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
	char			*champ_files[MAX_PLAYERS];

	if (-1 == parse_args(argc, &argv, champ_files))
		handle_error(NULL);
	if (-1 == init_game_struct(champ_files, &game))
		handle_error(&game);
	while (game.end_state == NOT_OVER)
	{
		if (0 > g_flags.cycle_intervals_to_dump)
		{
			if (-1 == game_rewind(champ_files, &game))
				handle_error(&game);
		}
		else if (++game.cycle_count &&
				(-1 == game_print(&game) || -1 == game_step(&game)))
			handle_error(&game);
		if (g_flags.list & FLAG_D
				&& g_flags.cycle_to_dump_exit <= game.cycle_count)
			game.end_state = GAME_DUMP;
	}
	if (-1 == game_print(&game))
		handle_error(&game);
	free_game(&game);
	return (0);
}
