/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 11:47:01 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 10:09:32 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** build_encoding build the encoding byte 
** returns 1 if error found with parameters
**
** encode:	encoding byte being built based on arg types
** i:		parameter number being analyzed
** pre:		first character of the parameter, used to determine arg type.
*/

static int	build_encoding(const t_op *op, char *encode, int i, char pre)
{
	if (pre == DIRECT_CHAR && (op->arg_type[i] & T_DIR))
		(*encode) |= (DIR_CODE << (2 * (MAX_ARGS_NUMBER - i - 1)));
	else if (pre == 'r' && (op->arg_type[i] & T_REG))
		(*encode) |= (REG_CODE << (2 * (MAX_ARGS_NUMBER - i - 1)));
	else if ((ft_isdigit(pre) || pre == LABEL_CHAR) && op->arg_type[i] & T_IND)
		(*encode) |= (IND_CODE << (2 * (MAX_ARGS_NUMBER - i - 1)));
	else
		return (1);
	return (0);
}

/*
** validate_parameters takes in the line and the op type and returns a list of
** validated parameters or NULL if the paramters are invalid.
*/

char	**validate_parameters(const t_op *op, char *line, char *encode)
{
	char		**ret;
	char		*tmp;
	int			i;

	if (!(ret = ft_strsplit(line, SEPARATOR_CHAR)))
		return (NULL);
	i = 0;
	while (ret[i])
	{
		if (!(tmp = ft_strtrim(ret[i])) || build_encoding(op, encode, i, *tmp))
		{
			free(tmp);
			return (delete_grid(ret));
		}
		free(ret[i]);
		ret[i] = tmp;
		i++;
	}
	ft_printf("\e[96maddress:%p\e[0m\n", tmp);
	if (i != op->argc)
		return (delete_grid(ret));
	return (ret);
}
