/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/05/02 20:27:14 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/*
**	Validate that the parameter encoding byte matches the parameters that are
**		alowed for this operation
*/

int		check_param_type(t_op op, char parameter_encoding)
{
	uint8_t		i;
	uint8_t		flag;

	i = 0;
	while (i < op.argc)
	{
		if (((parameter_encoding & 0xc0) >> 6) == REG_CODE)
			flag = T_REG;
		else if (((parameter_encoding & 0xc0) >> 6) == DIR_CODE)
			flag = T_DIR;
		else if (((parameter_encoding & 0xc0) >> 6) == IND_CODE)
			flag = T_IND;
		else
			return (-1);
		if ((flag & op.arg_type[i]) == 0)
			return (-1);
		parameter_encoding = parameter_encoding << 2;
		i++;
	}
	return (0);
}

char	parse_and_validate_parameters(struct s_game *game,
					struct s_process *process, struct s_parameter *params)
{
	int		ern;
	uint8_t **pc_temp;

	pc_temp = &process->pc;
	ern = 0;
	if (check_param_type(g_op_tab[process->op_code],
		*mask_ptr(game->arena, (*pc_temp + 1))))
		ern = -1;
	parse_parameters(game, process, params, pc_temp);
	return (ern);
}
