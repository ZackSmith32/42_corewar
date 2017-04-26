/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
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

static void	parse_init(int (*flag_set[NFLAGS])(char ***av, char **champ),
				char **champ, char **flags)
{
	flag_set[0] = &flag_d;
	flag_set[1] = &flag_n;
	flag_set[2] = &flag_p;
	flag_set[3] = &flag_s;
	flag_set[4] = &flag_v;
	flag_set[5] = &flag_f;
	flag_set[6] = &flag_w;
	ft_bzero(champ, sizeof(*champ) * MAX_PLAYERS);
	ft_bzero(&g_flags, sizeof(g_flags));
	g_flags.wait_time = 250000;
	*flags = VALID_FLAGS;
}

static void parse_exit(void)
{
	if (g_flags.list & FLAG_P || g_flags.list & FLAG_V)
	{
		initscr();
		noecho();
		curs_set(FALSE);
		clear();
		start_color();
		COLORS = 9;
		init_pair(8, 7, 7);
	}
}

int			parse_args(int ac, char ***av, char **champ)
{
	char		*flags;
	uintmax_t	func_code;
	int			(*flag_set[NFLAGS])(char ***av, char **champ);

	(ac == 1) ? print_usage(**av) : parse_init(flag_set, champ, &flags);
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
	parse_exit();
	return (0);
}
