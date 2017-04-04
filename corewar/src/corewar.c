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
#include <op.h>
#include <errno.h>
#include <libft.h>

//TODO: what's a sexy way to handle our errors
//TODO: priotity one: get everything to compile
//TODO: what's up with t_op? Figure out what is inside of t_op

int16_t				g_flags = 0;
int32_t				g_error = 0;
static char const	*g_error_msg[] = {
	"no error",
	"generic error"
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

	ft_bzero(&game, sizeof(game));
	if (-1 == flags_get(&argc, &argv))
		return (1);
	if (-1 == game_init(argc, argv, &game))
	{
		handle_error(&game);
	}
	while (game->winner == NULL)
	{
		if (game_step(&game) || game_print(&game))
		{
			handle_error(&game);
		}
	}
	free_game(&game);
	return (0);
}
