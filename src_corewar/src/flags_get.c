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

static int	flag_d(int *ac, char ***av, char **champ)
{
	(void)champ;
	if (--(*ac) && ++(*av) && **av && ***av < '0' && ***av > '9')
		return (-1);
	g_flags.cycle_to_dump_exit = ft_atoui(**av); //set params
	g_flags.list |= FLAG_D; //set g_flags
	return (0);
}

static int	flag_n(int *ac, char ***av, char **champ)
{
	unsigned int	i;

	i = 0;
	if (--(*ac) && ++(*av) && **av && ***av < '0' && ***av > '9'
			&& MAX_PLAYERS <= (i = ft_atoui(**av)) && champ[i] != NULL
			&& --(*ac) && ++(*av) && **av)
		return (-1);
	champ[i] = **av;
	g_flags.list |= FLAG_N;
	return (0);
}

static int	flag_p(int *ac, char ***av, char **champ)
{
	(void)ac;
	(void)av;
	(void)champ;
	g_flags.list |= FLAG_P;
	return (0);
}

static int	flag_s(int *ac, char ***av, char **champ)
{
	(void)champ;
	if (--(*ac) && ++(*av) && **av && ***av < '0' && ***av > '9')
		return (-1);
	g_flags.cycle_intervals_to_dump = ft_atoui(**av);
	g_flags.list |= FLAG_S;
	return (0);
}

static int	flag_v(int *ac, char ***av, char **champ)
{
	unsigned int	hex;

	(void)champ;
	hex = 0;
	if (--(*ac) && ++(*av) && **av && ***av < '0' && ***av > '9'
			&& 31 < (hex = ft_atoui(**av)))
		return (-1);
	g_flags.verbosity_level |= (1 << (hex));
	g_flags.list |= FLAG_V;
	return (0);
}

static void	print_flag_status(void)
{
	static int	count;

	count++;
	ft_printf("flag loop #%d\n", count);
	ft_printf("list %s\nbool %d%d%d%d%d%d\n", VALID_FLAGS, 
			g_flags.list & FLAG_D ? 1 : 0,
			g_flags.list & FLAG_N ? 1 : 0,
			g_flags.list & FLAG_P ? 1 : 0,
			g_flags.list & FLAG_S ? 1 : 0,
			g_flags.list & FLAG_V ? 1 : 0,
			g_flags.flag_test);
	ft_printf("cycle_intervals_to_dump=%d\n", g_flags.cycle_intervals_to_dump);
	ft_printf("cycle_to_dump_exit=%d\n", g_flags.cycle_to_dump_exit);
	ft_printf("verbosity_level %d%d%d%d%d\n\n",
			g_flags.verbosity_level & 0x1,
			g_flags.verbosity_level & 0x2,
			g_flags.verbosity_level & 0x4,
			g_flags.verbosity_level & 0x8,
			g_flags.verbosity_level & 0x10);
}

static int	flag_f(int *ac, char ***av, char **champ)
{
	(void)ac;
	(void)av;
	(void)champ;
	g_flags.flag_test = 1;
	return (0);
}

int			flags_get(int *ac, char ***av, char **champ)
{
	char		*flags;
	uintmax_t	func_code;
	int			(*flag_set[NFLAGS])(int *ac, char ***av, char **champ);

	flag_set[0] = &flag_d;
	flag_set[1] = &flag_n;
	flag_set[2] = &flag_p;
	flag_set[3] = &flag_s;
	flag_set[4] = &flag_v;
	flag_set[5] = &flag_f;
	ft_bzero(champ, sizeof(*champ) * MAX_PLAYERS + 1);
	ft_bzero(&g_flags, sizeof(g_flags));
	flags = VALID_FLAGS;
	while (--(*ac) && ++(*av) && **av && ***av == '-' && ++(**av))
	{
		ft_putstr("ac="); ft_putnbr(*ac); ft_putstr(" av="); ft_putendl(**av); //TEST
		if ((func_code = ft_strchr(flags, ***av) - flags) < NFLAGS
			&& ++(**av) && ***av == 0
			&& -1 == (flag_set[func_code])(ac, av, champ))
		{
			g_error = 4;
			return (-1);
		}

		ft_printf("function code #%d\n", func_code); //TEST
		if (g_flags.flag_test)
			print_flag_status();
	}
	ft_putstr("exit ac="); ft_putnbr(*ac); ft_putstr(" exit av="); ft_putendl(**av);
	exit(0); //TEST
	return (0);
}
