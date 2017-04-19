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

static int	flag_f(char ***av, char **champ)
{
	(void)av;
	(void)champ;
	g_flags.flag_test = 1;
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
			g_flags.verbosity_level & 0x1 ? 1 : 0,
			g_flags.verbosity_level & 0x2 ? 1 : 0,
			g_flags.verbosity_level & 0x4 ? 1 : 0,
			g_flags.verbosity_level & 0x8 ? 1 : 0,
			g_flags.verbosity_level & 0x10 ? 1 : 0);
}

static int	fill_champ(char ***av, char **champ)
{
	size_t	i;

	i = 0;
	while (**av && ***av)
	{
		while (champ[i])
			i++;
		if (MAX_PLAYERS < i)
			return (-1);
		champ[i] = **av;
		++(*av);
	}
	return (0);
}

static void	fill_flag_set(int (*flag_set[NFLAGS])(char ***av, char **champ))
{
	flag_set[0] = &flag_d;
	flag_set[1] = &flag_n;
	flag_set[2] = &flag_p;
	flag_set[3] = &flag_s;
	flag_set[4] = &flag_v;
	flag_set[5] = &flag_f;
}

int			flags_get(int ac, char ***av, char **champ)
{
	char		*flags;
	uintmax_t	func_code;
	int			(*flag_set[NFLAGS])(char ***av, char **champ);

	if (ac == 1)
		print_usage(**av);
	fill_flag_set(flag_set);
	ft_bzero(champ, sizeof(*champ) * MAX_PLAYERS + 1);
	ft_bzero(&g_flags, sizeof(g_flags));
	flags = VALID_FLAGS;
	while (++(*av) && **av && ***av == '-' && ++(**av))
	{
		if ((func_code = ft_strchr(flags, ***av) - flags) < NFLAGS
				&& ++(**av) && ***av == 0
				&& -1 == (flag_set[func_code])(av, champ) && (g_error = 3))
			return (-1);
		if (g_flags.flag_test)
			print_flag_status();
	}
	if (**av && -1 == fill_champ(av, champ) && (g_error = 3))
		return (-1);
	return (0);
}
