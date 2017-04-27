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

int	flag_w(char ***av, char **champ)
{
	(void)champ;
	if (++(*av) && **av && ***av >= '0' && ***av <= '9')
	{
		g_flags.wait_time = (useconds_t)ft_atoui(**av);
		if (g_flags.wait_time < 1000)
			g_flags.wait_time = 1000;
		return (0);
	}
	return (-1);
}

int	flag_f(char ***av, char **champ)
{
	(void)av;
	(void)champ;
	g_flags.flag_test = 1;
	return (0);
}
