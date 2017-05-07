/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/05/04 16:43:16 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include <op.h>

/*
** DIRECT
*/
# if DIR_SIZE == 1

typedef int8_t			t_dir;
# endif
# if DIR_SIZE == 2

typedef int16_t			t_dir;
# endif
# if DIR_SIZE == 3

typedef int32_t			t_dir;
# endif
# if DIR_SIZE == 4

typedef int64_t			t_dir;
# endif

/*
** REGISTER
*/
# if REG_SIZE == 1

typedef uint8_t			t_reg;
typedef int8_t			t_s_reg;
# endif
# if REG_SIZE == 2

typedef uint16_t		t_reg;
typedef int16_t			t_s_reg;
# endif
# if REG_SIZE == 4

typedef uint32_t		t_reg;
typedef int32_t			t_s_reg;
# endif
# if REG_SIZE == 8

typedef uint64_t		t_reg;
typedef int64_t			t_s_reg;
# endif

/*
** INDIRECT
*/
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

/*
** MAXIMUM ARG SIZE
*/
# if DIR_SIZE == 8 || REG_SIZE == 8 || IND_SIZE == 8

# define OP_ARG
typedef uint64_t		t_op_arg;
typedef int64_t			t_s_op_arg;
# endif
# ifndef OP_ARG
#  if DIR_SIZE == 4 || REG_SIZE == 4 || IND_SIZE == 4

#  define OP_ARG
typedef uint32_t		t_op_arg;
typedef int32_t			t_s_op_arg;
#  endif
# endif
# ifndef OP_ARG
#  if DIR_SIZE == 2 || REG_SIZE == 2 || IND_SIZE == 2

# define OP_ARG
typedef uint16_t		t_op_arg;
typedef int16_t			t_s_op_arg;
#  endif
# endif
# ifndef OP_ARG
#  if DIR_SIZE == 1 || REG_SIZE == 1 || IND_SIZE == 1

# define OP_ARG
typedef uint8_t		t_op_arg;
typedef int8_t			t_s_op_arg;
#  endif
# endif

#endif
