/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/19 22:57:38 by kdavis           ###   ########.fr       */
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
# include <ncurses.h>
# include <time.h>

struct					s_champ
{
	char	prog_name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
};

struct					s_flag
{
	int16_t				list; //bit list
	int					cycle_intervals_to_dump; // -option s
	unsigned int		cycle_to_dump_exit; // -option d
	int16_t				verbosity_level; // -option v bit list
	unsigned int		dump_per_second;
	_Bool				flag_test;
};

/*
** pc is the locaiton of the next instruction of execute
** called_live: if the process called the live operation in the last cycle
*/

typedef uint32_t		t_registor;

struct					s_process
{
	t_registor		registors[REG_NUMBER];
	_Bool			carry;
	uint8_t			*pc;
	unsigned int	countdown; //TODO: whats the maximum instruction execution time?
	uint8_t			op_code;
	_Bool			called_live;
	unsigned int    champ_index;
};

/*
** processes will be added to the front, so the yongest process is in front
** and they are incremented through front to back
** check_count: number of checks sense decrementing cycles to die
*/

enum					e_end_state
{
	NOT_OVER,
	WINNER_CHOSEN,
	GAME_DUMP
};

struct					s_game
{
	uint8_t				arena[MEM_SIZE];
	uint8_t				arena_writer[MEM_SIZE];
	struct s_champ		champs[MAX_PLAYERS];
	unsigned int		champ_count;
	t_list				*processes;
	unsigned int		cycles_to_death;
	unsigned int		current_cycles;
	unsigned int		check_count;
	struct s_champ		*last_live_champ;
	enum e_end_state	end_state;
	unsigned int		lives;
	unsigned int		cycle_count;
	t_strvec			aff_out;
};

/*
**	t_op contents:
**		> short name
**		> number of args it takes
**		> array: the args it takes
**		> number code of operation
**		> 5/10/6/20/25/50/1000/2 (number of cycles to execute command)
**		> long name
**		> 0: no encoding byte 1: encoding byte
**		> index flag: (direct and indirect are same size) 0/1
*/

typedef struct		s_op
{
	char		*name_short;
	int			argc;
	t_arg_type	arg_type[MAX_ARGS_NUMBER];
	int			op_code;
	int			cycles_required;
	char		*name_long;
	_Bool		encoding_byte;
	_Bool		dir_as_ind;
}						t_op;

typedef uint32_t		t_op_arg;

# if IND_SIZE == 1
typedef int8_t			t_ind;
# endif
# if IND_SIZE == 2
typedef int16_t			t_ind;
# endif
# if IND_SIZE == 4
typedef int32_t			t_ind;
# endif
# if IND_SIZE == 8
typedef int64_t			t_ind;
# endif

union					u_val
{
	uint8_t		arr[sizeof(t_op_arg)];
	t_op_arg	val;
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
** FLAG_V: debug output set
** FLAG_N: chamption position set
** FLAG_D: dump memory and exit after set cycles
** FLAG_S: dump memory after set cycles and repeat
** FLAG_P: pretty visual printing
*/

# define VALID_FLAGS	"dnpsvfw"
# define NFLAGS			7
# define FLAG_V			0x1
# define FLAG_N			0x2
# define FLAG_D			0x4
# define FLAG_S			0x8
# define FLAG_P			0x10
# define V_STATE		0x1
# define V_PROCESS		0x2
# define V_REGISTORS	0x4

# define OCTET_PER_LINE	64
# define HEX_HEADER		1
# define MAX_PROCESS	300

# define NUMBER_OF_FUNCTIONS 17

# define MAGIC_NUMBER 0xF383EA00

/*
** args/
*/
int						parse_args(int ac, char ***av, char **champ);
int						flag_d(char ***av, char **champ);
int						flag_n(char ***av, char **champ);
int						flag_p(char ***av, char **champ);
int						flag_s(char ***av, char **champ);
int						flag_v(char ***av, char **champ);
int						flag_f(char ***av, char **champ);
int						flag_w(char ***av, char **champ);
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
int						game_print(struct s_game *game);
void					print_game_state(struct s_game *game);
void					print_processes(uint8_t *arena, t_list *processes);
void					print_hex(void *loc, void *writer_loc, size_t size,
							t_list *processes);
uint32_t				color_code(t_list *processes);
void					win_resize(void);
_Bool					key_pause(char key);
void					key_wait(char key);
void					key_skip(char key);
void					key_rewind(char key);
int						game_rewind(char **champ_files, struct s_game *game);

/*
** free.c
*/
void					free_game(struct s_game *game);

/*
** utilities.c
*/
void					change_end(void *val, size_t size);
int						ft_jasprintf(t_strvec *ret, const char *format, ...);
void					arena_writer(struct s_game *game, uint8_t *loc,
							size_t offset, uint8_t champ_index);

/*
** operations/utilities
*/
void					move_pc(uint8_t *arena, uint8_t **pc, int move);
int						move_one(struct s_game *game,
							struct s_process *process);
uint8_t					*mask_ptr(uint8_t *arena, uint8_t *ptr);
uint8_t					*read_arena(uint8_t *arena, uint8_t *arena_ptr,
							uint8_t *norm_ptr, size_t size);
uint8_t					*write_arena(uint8_t *arena, uint8_t *arena_ptr,
							uint8_t *norm_ptr, size_t size);
void					reverse_bytes(uint8_t *ptr, size_t size, uint8_t *dest);

/*
** /operations/live_st_zjmp.c
*/
int						live(struct s_game *game, struct s_process *process);
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
** /operations/fork_lfork_aff.c
*/
int						fork_op(struct s_game *game, struct s_process *process);
int						lfork(struct s_game *game, struct s_process *process);
int						aff(struct s_game *game, struct s_process *process);

/*
** /operations/ld_lld.c
*/
int						ld(struct s_game *game, struct s_process *process);
int						lld(struct s_game *game, struct s_process *process);

/*
** /operations/ldi_lldi.c
*/
int						ldi(struct s_game *game, struct s_process *process);
int						lldi(struct s_game *game, struct s_process *process);

/*
** /operations/parse_parameters
*/
int						parse_parameters(struct s_game *game,
							struct s_process *process,
							struct s_parameter *params, uint8_t **pc_temp);
void					memmove_arg(uint8_t *arena, uint8_t *src,
							uint8_t *dst, size_t size);

/*
** /operations/validate_parameters
*/
char					parse_and_validate_parameters(struct s_game *game,
							struct s_process *process,
							uint8_t **pc_temp, struct s_parameter *params);

/*
** /operations/utilities2
*/
int						check_registors(uint8_t op_code,
							struct s_parameter *params);
void					modify_carry(struct s_process *process, t_op_arg ret);

							
#endif
