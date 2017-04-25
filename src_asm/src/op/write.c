/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:01:59 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/25 16:22:19 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Load the parameters into the output
**
** op:			holds information regarding the operation being parsed
** op_addr:		address of the op coding byte in the output vector
** params:		parameters for the op
** vector[0]:	output vector
** vector[1]:	label_call vector
*/

static int	transform_parameters(const t_op *op, int op_addr, char **params,
		t_op_parse *opp)
{
	int				i;

	i = 0;
	while (i < op->argc)
	{
		ft_printf("parsing:%s\n", params[i]);///
		if ((params[i][0] == LABEL_CHAR) ||
				(params[i][1] == DIRECT_CHAR && (params[i][1] == LABEL_CHAR)))
		{
			add_label_call(op, opp, op_addr, params[i]);
		}
		else
			;
		i++;
	}
	return (0);
}

/*
** Appends the op_code for this operation, and encoding byte if the op has one
*/

static int	initialize_output(int op_code, char encode, t_vec *output)
{
	char	code;

	code = (char)op_code;
	ft_printf("Append code byte\n");///
	if (!(ft_vecapp(output, &code, 1)))
		return (1);
	if (g_op_tab[op_code].encoding_byte)
		if (!(ft_vecapp(output, &encode, 1)))
			return (1);
	return (0);
}


/*
** write_op will write the byte code to the output vector, and keep track of
** label_calls.
*/

int	write_op(int op_code, char *line, t_op_parse *opp)
{
	const t_op	*op;
	char		**params;
	int			op_addr;
	char		encode;

	encode = 0;
	op_addr = opp->output.len;
	op = &g_op_tab[op_code];
	ft_printf("op:%s line:%s\n", op->name_short, line);
	if (!(params = validate_parameters(op, line, &encode)))
		return (1);
	if (initialize_output(op_code, encode, &opp->output))
		return (1);
	if (transform_parameters(op, op_addr, params, opp))
		return (1);
/*	if (transform_parameters(op_addr, params, output, label_calls))
		return (1);*/
	return (0);
}
