/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2017/04/13 14:56:21 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		add_process(uint8_t *arena, struct s_process *base_process,
						t_ind offset, t_list **processes)
{
	struct s_process	*p;
	t_list				*link;

	if (NULL == (p = ft_memdup(base_process, sizeof(*base_process))))
		return (-1);
	p->op_code = *p->pc;
	p->countdown = g_op_tab[p->op_code].cycles_required;
	p->pc = mask_ptr(arena, p->pc + offset);
	if (NULL == (link = lstnew(p)))
		return (-1);
	lstadd(processes, link);
	return (0);
}

int				fork_op(struct s_game *game, struct s_process *process)
{
	t_ind		offset;

	read_arena(game->arena, process->pc + 1, (uint8_t*)&offset,
		sizeof(offset));
	change_end(&offset, sizeof(offset));
	offset %= IDX_MOD;
	if (-1 == add_process(game->arena, process, offset, &game->processes))
		return (-2);
	process->pc = mask_ptr(game->arena, process->pc + IND_SIZE);
	return (0);
}

int				lfork(struct s_game *game, struct s_process *process)
{
	t_ind		offset;

	read_arena(game->arena, process->pc + 1, (uint8_t*)&offset,
		sizeof(offset));
	change_end(&offset, sizeof(offset));
	if (-1 == add_process(game->arena, process, offset, &game->processes))
		return (-2);
	process->pc = mask_ptr(game->arena, process->pc + IND_SIZE);
	process->carry = (offset == 0) ? 1 : 0; //TODO: is this right?
	return (0);
}

int				aff(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[16].argc];
	uint8_t				*pc_temp;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	process->pc = pc_temp;
	if (params[0].param_val.val >= REG_NUMBER)
		return (0);
	params[0].param_val.val = process->registors[params[0].param_val.val];
	change_end(&params[0].param_val.val, REG_SIZE);
	params[0].param_val.val = params[0].param_val.val % 256;
	ft_jasprintf(&game->aff_out, "%c", (char)params[0].param_val.val);
	process->carry = (params[0].param_val.val == 0) ? 1 : 0;
	return (0);
}
