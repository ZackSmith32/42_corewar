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
# include <libft.h>
# include <op.h>

struct			s_champ
{
  	char			prog_name[PROG_NAME_LENGTH + 1];
  	char			comment[COMMENT_LENGTH + 1];
	unsigned int	lives;
};

/*
** pc is the locaiton of the next instruction of execute
*/

struct			s_process
{
	unsigned char	registors[REG_NUMBER];
	_Bool			cary;
	void			*pc;
	unsigned int	countdown; //TODO: whats the maximum instruction execution time?
};

struct			s_game
{
	char				arena[MEM_SIZE];
	struct s_champ		*champs;
	t_vec				processes;
	unsigned int		time_to_death;
	struct s_champ		*winner;
};

typedef struct	s_op
{
	char		*name_short;
	int			i_dont_know;
	t_arg_type	arg_type;
	int			i_dont_know2;
	int			i_dont_know3;
	char		*name_long;
	int			i_dont_know4;
	int			i_dont_know5;
}				t_op;

extern int16_t	g_flags;
extern t_op		g_op_tab[17];
extern int32_t	g_error;

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

/*
**
*/
void			free_game(struct s_game *game);

#endif
