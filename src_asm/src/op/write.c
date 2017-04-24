/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:01:59 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/24 16:28:08 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>


/*
** write_op will write the byte code to the output vector, and keep track of
** label_calls.
*/

int	write_op(int op_code, char *line, t_vec *output, t_vec *label_calls)
{
	char	encode;
	char	**params;

	encode = 0;
	ft_printf("op:%s line:%s\n", g_op_tab[op_code].name_short, line);
	if (!(params = validate_parameters(op_code, line, &encode)))
		return (1);
	
	(void)op_code;
	(void)line;
	(void)output;
	(void)label_calls;
	return (0);
}
