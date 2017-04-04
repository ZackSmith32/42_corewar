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

//TODO: whats a sexy way to handle our errors

int16_t	g_flags;

static void		handle_error(struct s_game *game)
{
	free_game(game);
	exit(1);
}

int				main(int argc, char **argv)
{
	struct s_game	game;

	ft_bzero(&game, sizeof(game));
	if (-1 == flags_get(&argc, &argv))
		return (1);
	if (-1 == game_init(argc, argv, &game))
	{
		handle_error(&game);
	}
	while (game->winner != NULL)
	{
		if (game_step(&game) || game_print(&game))
		{
			handle_error(&game);
		}
	}
	free_game(&game);
	return (0);
}