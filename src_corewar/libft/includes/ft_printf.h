/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:11:33 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/09 08:15:56 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	lm -1 = no 	int				unsigned int
**	lm  0 = hh	char			unsigned char
**	lm  1 = h 	short			unsigned short
**	lm  2 = l	long			unsigned long
**	lm  3 = ll	long long		unsigned long long
**	lm  4 = z	ssize_t			size_t
**	lm  5 = j	intmax_t		uintmax_t
*/

# include <string.h>
# include <stdarg.h>
# include "ft_io.h"
# include "ft_string.h"
# include "ft_memory.h"

# define LCONVERSION 		"DOUCS"
# define SNUMCONVERSION		"diD"
# define UNUMCONVERSION		"ouxpOUXb"
# define CHARCONVERSION		"cC"
# define STRCONVERSION		"sS"
# define CONVERSIONS		"diDouxpOUXbcCsS"
# define FLAGS				"#0- +.$"
# define LM					"jzhl"

typedef struct			s_pfflag
{
	int					findex;
	int					lm;
	int					mfw;
	int					prcn;
	char				conv;
	char				is_con;
	char				hf;
	char				zf;
	char				mf;
	char				sf;
	char				pf;
}						t_pfflag;

typedef struct			s_vdata
{
	intmax_t			s;
	uintmax_t			u;
	char				*p;
	wint_t				c;
}						t_vdata;

typedef struct			s_pf_print
{
	unsigned long long	ba;
	uintmax_t			udata;
	intmax_t			sdata;
	int					prcn_pad;
	int					put;
	int					h;
}						t_pf_print;

extern int				(*g_farray[15])(t_vdata *, t_pfflag *, t_strvec *);

/*
** Printf functions:
*/

int						ft_dprintf(int fd, const char *format, ...);
int						ft_printf(const char *format, ...);
int						ft_vasprintf(t_strvec *ret, const char *fm, va_list ap);
int						ft_vdprintf(int fd, const char *format, va_list ap);

/*
** pf_flag_reader:
*/

const char				*pf_read_format(const char *fstr,
							va_list ap, t_strvec *h);

/*
** pf_append_data:
*/

int						pf_append_data(t_vdata *dta, t_pfflag *fl, t_strvec *h);

/*
** pf_funcarray:
*/

int						pf_farray(int ret);

/*
** pf_nbr_funcs:
*/

int						pf_di(t_vdata *data, t_pfflag *fl, t_strvec *vec);
int						pf_xp(t_vdata *data, t_pfflag *fl, t_strvec *vec);
int						pf_ub(t_vdata *data, t_pfflag *fl, t_strvec *vec);
int						pf_o(t_vdata *data, t_pfflag *fl, t_strvec *vec);

/*
** pf_str_funcs:
*/

int						pf_c(t_vdata *data, t_pfflag *fl, t_strvec *vec);
int						pf_s(t_vdata *data, t_pfflag *fl, t_strvec *vec);

/*
** pf_alloc_ret:
*/

int						pf_alloc_ret(int ret, char *s1, char *s2, char *s3);

#endif
