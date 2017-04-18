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

int	flag_d(char ***av, char **champ)
{
	(void)champ;
	if (++(*av) && **av && ***av >= '0' && ***av <= '9')
	{
		g_flags.cycle_to_dump_exit = ft_atoui(**av);
		g_flags.list |= FLAG_D;
		return (0);
	}
	return (-1);
}

int	flag_n(char ***av, char **champ)
{
	unsigned int	i;

	i = 0;
	if (++(*av) && **av && ***av >= '0' && ***av <= '9'
			&& MAX_PLAYERS > (i = ft_atoui(**av) - 1) && champ[i] == NULL
			&& ++(*av) && **av)
	{
		champ[i] = **av;
		g_flags.list |= FLAG_N;
		return (0);
	}
	return (-1);
}

int	flag_p(char ***av, char **champ)
{
	(void)av;
	(void)champ;
	g_flags.list |= FLAG_P;
	return (0);
}

int	flag_s(char ***av, char **champ)
{
	(void)champ;
	if (++(*av) && **av && ***av >= '0' && ***av <= '9')
	{
		g_flags.cycle_intervals_to_dump = ft_atoui(**av);
		g_flags.list |= FLAG_S;
		return (0);
	}
	return (-1);
}

int	flag_v(char ***av, char **champ)
{
	unsigned int	hex;
	char			**nxt;

	(void)champ;
	hex = 0;
	nxt = *av + 1;
	if (nxt && *nxt && **nxt >= '0' && **nxt <= '9' && ++(*av))
		hex = ft_atoui(**av);
	else
		hex = 31;
	if (31 >= hex)
	{
		g_flags.verbosity_level |= hex;
		g_flags.list |= FLAG_V;
		return (0);
	}
	return (-1);
}
