/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:01:59 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 15:21:06 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Load the parameters into the output
**
** op:			holds information regarding the operation being parsed
** op_addr:		address of the op coding byte in the output vector
** params:		parameters for the op
** opp:			Holds vectors for output and label_calls
*/

static int	transform_parameters(const t_op *op, int op_addr, char **params,
		t_op_parse *opp)
{
	int				i;

	i = 0;
	while (i < op->argc)
	{
		if ((params[i][0] == LABEL_CHAR) ||
				(params[i][0] == DIRECT_CHAR && (params[i][1] == LABEL_CHAR)))
		{
			if (add_label_call(op, opp, op_addr, params[i]))
				return (1);
		}
		else if (add_param(op, &opp->output, params[i]))
			return (1);
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

int			write_op(int op_code, char *line, t_op_parse *opp)
{
	const t_op	*op;
	char		**params;
	int			op_addr;
	int			ern;
	char		encode;

	encode = 0;
	op_addr = opp->output.len;
	op = &g_op_tab[op_code];
	if (!(params = validate_parameters(op, line, &encode)))
		return (1);
	if ((ern = initialize_output(op_code, encode, &opp->output)) == 0)
		ern = transform_parameters(op, op_addr, params, opp);
	delete_grid(params);
	return (ern);
}
