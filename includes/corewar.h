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

#ifndef COREWAR_H
# define COREWAR_H

# include <stdint.h>

struct			s_champ
{
  	char			prog_name[PROG_NAME_LENGTH + 1];
  	char			comment[COMMENT_LENGTH + 1];
	unsigned int	lives;
};

/*
** pc stands for process
*/
struct			s_pc
{
	unsigned char	registors[8] //TODO: how many registers are there and what size are they?
	_Bool			cary;
	size_t			location; //TODO: index or pointer?
	unsigned int	countdown; //TODO: whats the maximum instruction execution time?
};

struct			s_game
{
	char				arena[MEM_SIZE];
	struct s_champ		*champs;
	struct t_vect		*pc;
	unsigned int		time_to_death;
	struct s_champ		*winner;
};

typedef struct	s_op
{
	char		*name_short;
	int
	t_arg_type	arg_type;
	int
	int
	char		*name_long;
	int
	int
}				t_op;

extern int16_t	g_flags;
extern t_op		g_op_tab[17];

# define	FLAG_V		0x1
# define	FLAG_N		0x2
# define	FLAG_D		0x4
# define	FLAG_S		0x8
# define	FLAG_B		0x10

/*
** flags_get.c
*/
int				flags_get(int *argc, char ***argv);

/*
** game_init.c
*/
int				game_init(int argc, char **argv, struct s_game *game);

/*
** game_step/game_step.c
*/
int				game_step(struct s_game *game);

/*
** game_print/game_print.c
*/
int				game_print(struct s_game *game);

#endif
