/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	print_usage(char *filename)
{
	ft_printf("Usage: %s %s%s%s%s%s%s%d%s%s%d%s%s%s%s%s%s%d%s%s%d%s",
		filename, "[-d N -s N -v [N] | -p] [-n N <champion1.cor>] <...>\n",
		"-d N       : Dumps memory after N cycles then exits\n",
		"-s N       : Runs N cycles, dumps memory, pauses, then repeats\n",
		"-v N       : Verbosity levels, can be added together to enable",
		" several, N is optional, default is all\n",
		"             - ", V_STATE, " : Show game state\n",
		"             - ", V_PROCESS, " : Show process list\n",
		"-p         : Display memory byte map\n",
		"-n N <...> : Explicitly choose champion position\n",
		"-w N       : Wait time in microseconds, default 250000\n",
		"Game Settings:\n",
		"-Max Players    : ", MAX_PLAYERS, "\n",
		"-Max Champ Size : ", CHAMP_MAX_SIZE, " bytes\n"
		);
	exit(0);
}
