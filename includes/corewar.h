/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/05 13:44:18 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdint.h>
# include <stdbool.h>
# include <libft.h>
# include <op.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fctl.h>

struct				s_champ
{
  	char			prog_name[PROG_NAME_LENGTH + 1];
  	char			comment[COMMENT_LENGTH + 1];
	unsigned int	lives;
	_Bool			alive;
};

struct					s_flag
{
	int16_t				list; //bit list
	unsigned int		cycle_intervals_to_dump; // -option s
	unsigned int		cycle_to_dump_exit; // -option d
	int16_t				verbosity_level; // -option v bit list
};

/*
** pc is the locaiton of the next instruction of execute
*/

struct				s_process
{
	unsigned char	registors[REG_NUMBER];
	_Bool			cary;
	void			*pc;
	unsigned int	countdown; //TODO: whats the maximum instruction execution time?
	unsigned int	op_code;
};

struct				s_game
{
	uint8_t				arena[MEM_SIZE];
	struct s_champ		champs[MAX_PLAYERS];
	unsigned int		champ_count;
	t_vec				processes;
	unsigned int		cycles_max;
	unsigned int		cycles_to_death;
	struct s_champ		*last_live_champ;
	struct s_champ		*winner;
};

typedef struct		s_op
{
	char		*name_short;
	int			argc;
	t_arg_type	arg_type[MAX_ARGS_NUMBER];
	int			op_code;
	int			cycles_required;
	char		*name_long;
	_Bool		i_dont_know4;
	_Bool		i_dont_know5;
}				t_op;

extern struct s_flag	g_flags;
extern t_op	const		g_op_tab[17];
extern int				(*g_op_pointers[17])(struct s_game*, struct s_process*);
extern int32_t			g_error;

# define	VALID_FLAGS	"dnpsv"
# define	NFLAGS		5
# define	FLAG_V		0x1
# define	FLAG_N		0x2
# define	FLAG_D		0x4
# define	FLAG_S		0x8
# define	FLAG_P		0x10

# define	NUMBER_OF_FUNCTIONS 17;

/*
** flags_get.c
*/
int					flags_get(int *ac, char ***av, char ***champ);

/*
** game_init.c
*/
int					game_init(char const ***champs, struct s_game *game);

/*
** game_step/game_step.c
*/
int					game_step(struct s_game *game);

/*
** game_print/game_print.c
*/
int					game_print(struct s_game *game);

/*
**
*/
void				free_game(struct s_game *game);

/*
** helpers.c
** idealy these functions will move to more appropriate folders
*/
//what's the max move size?
void				move_pc(uint8_t *arena, void **pc, int move); 

#endif
