/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:01:59 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/24 16:50:28 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*int	transform_parameters(int op_code, char **params, t_vec *out_info[2],
		char encode)
{
	t_vec	*label_calls;
	t_vec	*output;
	int		size;
	int		i;

	label_calls = out_info[1];
	output = out_info[1];
	i = 0;
	while (
}*/


/*
** write_op will write the byte code to the output vector, and keep track of
** label_calls.
*/

int	write_op(int op_code, char *line, t_vec *output, t_vec *label_calls)
{
	t_vec	*out_info[2];
	char	encode;
	char	**params;

	encode = 0;
	out_info[0] = output;
	out_info[1] = label_calls;
	ft_printf("op:%s line:%s\n", g_op_tab[op_code].name_short, line);
	if (!(params = validate_parameters(op_code, line, &encode)))
		return (1);
/*	if (transform_parameters(op_code, params, out_info, encode))
		return (1);*/
	(void)output;
	(void)label_calls;
	return (0);
}
