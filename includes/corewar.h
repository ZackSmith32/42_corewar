/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/17 18:35:57 by zsmith           ###   ########.fr       */
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
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

struct					s_champ
{
  	char			prog_name[PROG_NAME_LENGTH + 1];
  	char			comment[COMMENT_LENGTH + 1];
};

struct					s_flag
{
	int16_t				list; //bit list
	unsigned int		cycle_intervals_to_dump; // -option s
	unsigned int		cycle_to_dump_exit; // -option d
	int16_t				verbosity_level; // -option v bit list
	_Bool				flag_test;
};

/*
** pc is the locaiton of the next instruction of execute
** called_live: if the process called the live operation in the last cycle
*/

// TODO: should this be singed?
typedef uint32_t		registor_t;

struct					s_process
{
	registor_t		registors[REG_NUMBER];
	_Bool			carry;
	uint8_t			*pc;
	unsigned int	countdown; //TODO: whats the maximum instruction execution time?
	uint8_t			op_code;
	_Bool			called_live;
};

/*
** processes will be added to the front, so the yongest process is in front
** and they are incremented through front to back
** check_count: number of checks sense decrementing cycles to die
*/

struct					s_game
{
	uint8_t				arena[MEM_SIZE];
	struct s_champ		champs[MAX_PLAYERS];
	unsigned int		champ_count;
	t_list				*processes;
	unsigned int		cycles_to_death;
	unsigned int		current_cycles;
	unsigned int		check_count;
	struct s_champ		*last_live_champ;
	_Bool				game_over;
	unsigned int		lives;
};

typedef struct			s_op
{
	char		*name_short;
	int			argc;
	t_arg_type	arg_type[MAX_ARGS_NUMBER];
	int			op_code;
	int			cycles_required;
	char		*name_long;
	_Bool		encoding_byte;
	_Bool		dir_as_ind;
}				t_op;

typedef uint64_t		op_arg_t;

union				u_val
{
	uint8_t		arr[sizeof(op_arg_t)];
	op_arg_t	val;
};

struct					s_parameter
{
	uint8_t				param_type;
	union u_val			param_val;
};

extern struct s_flag	g_flags;
extern t_op	const		g_op_tab[];
extern int				(*g_op_pointers[17])(struct s_game*, struct s_process*);
extern int32_t			g_error;


/*
**	FLAG_V: debug output set
**	FLAG_N: chamption position set
**	FLAG_D: dump memory and exit after set cycles
**	FLAG_S: dump memory after set cycles and repeat
**	FLAG_P: pretty visual printing
*/

# define	VALID_FLAGS	"dnpsvf"
# define	NFLAGS		6
# define	FLAG_V		0x1
# define	FLAG_N		0x2
# define	FLAG_D		0x4
# define	FLAG_S		0x8
# define	FLAG_P		0x10
# define	V_STATE		0x1
# define	V_PROCESS	0x2

# define	NUMBER_OF_FUNCTIONS 17

# define	MAGIC_NUMBER 0xF383EA00

/*
** args/
*/
int						parse_args(int ac, char ***av, char **champ);
int						flag_d(char ***av, char **champ);
int						flag_n(char ***av, char **champ);
int						flag_p(char ***av, char **champ);
int						flag_s(char ***av, char **champ);
int						flag_v(char ***av, char **champ);
void					print_usage(char *filename);

/*
** game_init.c
*/
int						init_game_struct(char **champs, struct s_game *game);

/*
** game_step/game_step.c
*/
int						game_step(struct s_game *game);

/*
** game_print/
*/
char					*ft_strnjoin(char const *s1, char const *s2,
							size_t s2_len);
int						ft_jasprintf(t_strvec *ret, const char *format, ...);
int						game_print(struct s_game *game, t_strvec *out);
void					print_hex(t_strvec *out, void *loc, size_t size,
							t_list *processes);

/*
** free.c
*/
void					free_game(struct s_game *game);

/*
** operations/utilities
*/
void					move_pc(uint8_t *arena, uint8_t **pc, int move);
int						move_one(struct s_game *game,
							struct s_process *process);
uint8_t					*mask_ptr(uint8_t *arena, uint8_t *ptr);
size_t					calc_offset(struct s_parameter *params, int argc);
uint8_t		*read_arena(uint8_t *arena, uint8_t *arena_ptr, uint8_t *norm_ptr, size_t size);
uint8_t		*write_arena(uint8_t *arena, uint8_t *arena_ptr, uint8_t *norm_ptr, size_t size);
void		reverse_bytes(uint8_t *ptr, size_t size, uint8_t *dest);


/*
** /operations/live
*/
int						live(struct s_game *game, struct s_process *process);
int						ld(struct s_game *game, struct s_process *process);
int						st(struct s_game *game, struct s_process *process);
int						zjmp(struct s_game *game, struct s_process *process);

/*
** /operations/sti.c
*/
int						sti(struct s_game *game, struct s_process *process);

/*
** /operations/add_sub.c
*/
int						add(struct s_game *game, struct s_process *process);
int						sub(struct s_game *game, struct s_process *process);

/*
** /operations/and_or_xor.c
*/
int						and(struct s_game *game, struct s_process *process);
int						or(struct s_game *game, struct s_process *process);
int						xor(struct s_game *game, struct s_process *process);

/*
** /operations/parse_parameters
*/
int			parse_parameters(struct s_game *game, struct s_process *process, 
				struct s_parameter *params,
				uint8_t **pc_temp);
void					memmove_arg(uint8_t *arena, uint8_t *src,
							uint8_t *dst, size_t size);

/*
** /operations/validate_parameters
*/
char		parse_and_validate_parameters(struct s_game *game, struct s_process *process,
				uint8_t **pc_temp, struct s_parameter *params);

/*
** /operations/utilities2
*/
int			check_registors(uint8_t op_code, struct s_parameter *params);
#endif
