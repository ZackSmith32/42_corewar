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

static int	flag_d(int *ac, char ***av, char ***champ, struct s_flag *flag)
{
	(void)champ;
	if (--(*ac) && ++(*av) && **av && ***av < '0' && ***av > '9')
		return (-1);
	flag->cycle_to_dump_exit = ft_atoui(**av); //set params
	g_flags |= (1 << (FLAG_D)); //set g_flags
	return (0);
}

static int	flag_n(int *ac, char ***av, char ***champ, struct s_flag *flag)
{
	unsigned int	i;

	(void)flag;
	i = 0;
	if (--(*ac) && ++(*av) && **av && ***av < '0' && ***av > '9'
			&& MAX_PLAYERS <= (i = ft_atoui(**av)) && *champ[i] != NULL
			&& --(*ac) && ++(*av) && **av)
		return (-1);
	*champ[i] = **av;
	return (0);
}

static int	flag_p(int *ac, char ***av, char ***champ, struct s_flag *flag)
{
	(void)ac;
	(void)av;
	(void)champ;
	(void)flag;
	g_flags |= (1 << (FLAG_P));
	return (0);
}

static int	flag_s(int *ac, char ***av, char ***champ, struct s_flag *flag)
{
	(void)champ;
	if (--(*ac) && ++(*av) && **av && ***av < '0' && ***av > '9')
		return (-1);
	flag->cycle_intervals_to_dump = ft_atoui(**av);
	g_flags |= (1 << (FLAG_D));
	return (0);
}

static int	flag_v(int *ac, char ***av, char ***champ, struct s_flag *flag)
{
	int	hex;

	(void)champ;
	hex = 0;
	if (--(*ac) && ++(*av) && **av && ***av < '0' && ***av > '8'
			&& 16 <= (hex = ft_atoui(**av)) && hex != (hex & -hex))
		return (-1);
	flag->verbosity_level |= (1 << (hex));
	g_flags |= (1 << (FLAG_V));
	return (0);
}

int			flags_get(int *ac, char ***av, char ***champ, struct s_flag *flag)
{
	char		*flags;
	uintmax_t	func_code;
	int			(*flag_set[NFLAGS])
					(int *ac, char ***av, char ***champ, struct s_flag *flag);

	flag_set[0] = &flag_d;
	flag_set[1] = &flag_n;
	flag_set[2] = &flag_p;
	flag_set[3] = &flag_s;
	flag_set[4] = &flag_v;
	ft_bzero(champ, sizeof(*champ) * MAX_PLAYERS + 1);
	ft_bzero(&g_flags, sizeof(g_flags));
	flags = VALID_FLAGS;
	while (--(*ac) && ++(*av) && **av && ***av == '-'
			&& (func_code = ft_strchr(flags, ++(***av)) - flags) < NFLAGS
			&& ++(***av) == 0)
		if (-1 == (flag_set[func_code])(ac, av, champ, flag))
		{
			g_error = 4;
			return (-1);
		}
	return (0);
}
