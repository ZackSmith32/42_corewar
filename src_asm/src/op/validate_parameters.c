/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 11:47:01 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/24 15:04:51 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	**delete_grid(char **grid)
{
	size_t	i;

	while (grid[i])
	{
		ft_memdel((void*)&grid[i]);
		i++;
	}
	ft_memdel((void*)&grid);
	return (NULL);
}

/*static char	*transform_parameter(char *input, t_vec *label_calls)
{
}*/

/*
** build_encoding build the encoding byte 
** returns 1 if error found with parameters
**
** encode:	encoding byte being built based on arg types
** i:		parameter number being analyzed
** pre:		first character of the parameter, used to determine arg type.
*/

static int	build_encoding(char *encode, int i, char pre)
{
	char	mask;

	mask = 0xC0;
	if (pre == DIRECT_CHAR && (op->arg_type[i] & T_DIR) && !op->dir_as_ind)
		encode |= (DIR_CODE << (2 * (MAX_ARGS_NUMBER - i - 1)));
	else if (pre == 'r' && (op->arg_type[i] & T_REG))
		encode |= (REG_CODE << (2 * (MAX_ARGS_NUMBER - i - 1)));
	else if (ft_isdigit(pre) || pre == LABEL_CHAR &&
			((op->arg_type[i] & T_IND) || (op->arg_type[i] & T_DIR)))
		encode |= (IND_CODE << (2 * (MAX_ARGS_NUMBER - i - 1)));
	else
		return (1);
	return (0);
}

/*
** validate_parameters takes in the line and the op type and returns a list of
** validated parameters or NULL if the paramters are invalid.
*/

char	**validate_parameters(int op_code, char *line, t_vec *label_calls,
		char *encode)
{
	const t_op	*op;
	char		**ret;
	char		*tmp;
	int			i;

	if (!(ret = ft_strsplit(line, SEPERATOR_CHAR)))
		return (NULL);
	op = &g_op_tab[op_code];
	i = 0;
	while (ret[i])
	{
		if (!(tmp = ft_strtrim(ret[i])) || build_encoding(encode, i, *tmp))
			return (delete_grid(ret));
		free(ret[i]);
/*		if (!(ret[i] = transform_parameter(tmp, label_calls)))
			return (delete_grid(ret));*/
		i++;
	}
	ft_printf("encoding byte:%hhx\n", encode);
	return (ret);
}
