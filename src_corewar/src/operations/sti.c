/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by aphan             #+#    #+#             */
/*   Updated: 2017/04/17 23:11:04 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void			change_end32(void *val, size_t size)
{
	uint8_t 		*start;
	unsigned int	rval;
	size_t			i;

	rval = *((short int *)val);
	start = (uint8_t*)val;
	i = 0;
	while (size-- > 0)
	{
		start[i] = ((uint8_t *)&rval)[size];
		i++;
	}
}

static void			change_end_alt(void *val, size_t size)
{
	uint8_t swap;
	uint8_t *start;
	uint8_t	*end;

	if (size == REG_SIZE)
		change_end32(val, size);
	else
	{
		start = (uint8_t*)val;
		end = start + size - 1;
		while (end > start)
		{
			swap = *start;
			*start = *end;
			*end = swap;
			end--;
			start++;
		}
	}
}

//DO I NEED TO CHANGE_END FOR TYPE T_REG????
int		sti(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[11].argc];
	uint8_t				*pc_temp;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	if (-1 == check_registors(process->op_code, params)
			&& (process->pc = pc_temp))
		return (0);
	params[0].param_val.val = process->registors[params[0].param_val.val - 1];
	change_end_alt(params[0].param_val.arr, REG_SIZE);
	if (params[1].param_type == T_IND || params[1].param_type == T_DIR)
		change_end_alt(params[1].param_val.arr, IND_SIZE);
	else if (params[1].param_type == T_REG)
		params[1].param_val.val =
				process->registors[params[1].param_val.val - 1];
	if (params[2].param_type == T_DIR)
		change_end_alt(params[2].param_val.arr, IND_SIZE);
	else if (params[2].param_type == T_REG)
		params[2].param_val.val =
				process->registors[params[2].param_val.val - 1];
	write_arena(game->arena,
			process->pc + params[1].param_val.val + params[2].param_val.val, 
			(uint8_t *)&params[0].param_val.val, REG_SIZE);
	process->pc = pc_temp;
	return (0);
}
