/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:44:59 by aphan             #+#    #+#             */
/*   Updated: 2017/05/01 15:45:01 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	key_scroll(int key)
{
	if (key == 'u')
		g_flags.top_process = 0;
	else if (key == 'p')
		g_flags.top_process += 100;
	else if (key == 'o')
		g_flags.top_process += 1;
	else if (key == 'i')
		g_flags.top_process = (g_flags.top_process > 0)
			? g_flags.top_process - 1 : 0;
	printw("top_process[uiop]: %-4d  ", g_flags.top_process + 1);
}

