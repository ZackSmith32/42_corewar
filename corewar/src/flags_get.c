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

// REMINDER: extern int16_t		g_flags;


# define SETBIT(A,k)	(A[(k/32)] |= (1 << (k%32)))
# define CLEARBIT(A,k)	(A[(k/32)] &= ~(1 << (k%32)))
# define TESTBIT(A,k)	(A[(k/32)] & (1 << (k%32)))
# define VALID_FLAGS	"dnpsv"
# define NFLAGS			5


static int	flag_d(int *ac, char ***av, char ***champ, struct s_game *game)
{

	//set params
	//set g_flags
	//increment ac av as needed
	return (0);
	
	//set fail case like invalid next argv
	return (-1);
}

int			flags_get(int *ac, char ***av, char ***champ, struct s_game *game)
{
	int					j;
	char				*flags;
	uintmax_t			func_code;
	int					(*flag_set[NFLAGS])(int *ac, char ***av,
											char ***champ, struct s_game *game)

	flag_set = {&flag_d, &flag_n, &flag_p, &flag_s, &flagv};
	ft_bzero(champions, sizeof(*champions) * MAX_PLAYERS);
	ft_bzero(g_flags, sizeof(g_flags));
	flags = VALID_FLAGS;
	while (--(*ac) && ++(*av) && **av && (*(*av)) == '-' 
			&& (func = flags - ft_strchr(flags, *(*av))) < NFLAGS
			&& (*(*av)) == 0)
	{
		if ( -1 == (flag_set[func_code])(ac, av, champ, game))
			//handle error
	}
	return (0);
}
