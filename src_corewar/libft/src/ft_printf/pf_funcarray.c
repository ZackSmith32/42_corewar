/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_funcarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:34:01 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/07 16:23:06 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

int	(*g_farray[15])(t_vdata *, t_pfflag *, t_strvec *);

int	pf_farray(int ret)
{
	g_farray[0] = &pf_di;
	g_farray[1] = &pf_di;
	g_farray[2] = &pf_di;
	g_farray[3] = &pf_o;
	g_farray[4] = &pf_ub;
	g_farray[5] = &pf_xp;
	g_farray[6] = &pf_xp;
	g_farray[7] = &pf_o;
	g_farray[8] = &pf_ub;
	g_farray[9] = &pf_xp;
	g_farray[10] = &pf_ub;
	g_farray[11] = &pf_c;
	g_farray[12] = &pf_c;
	g_farray[13] = &pf_s;
	g_farray[14] = &pf_s;
	return (ret);
}
