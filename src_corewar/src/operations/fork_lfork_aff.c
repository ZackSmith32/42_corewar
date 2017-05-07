/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_lfork_aff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2017/05/04 16:50:30 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

//TODO: do forks get op immediatly or at the end of cycle
static int		add_process(uint8_t *arena, struct s_process *base_process,
						t_ind offset, t_list **processes)
{
	struct s_process	*p;
	t_list				*link;

	if (NULL == (p = ft_memdup(base_process, sizeof(*base_process))))
		return (-1);
	p->pc = mask_ptr(arena, p->pc + offset);
	p->pid = g_flags.pid++;
	if (NULL == (link = lstnew(p)))
		return (-1);
	lstadd(processes, link);
	return (0);
}

int				fork_op(struct s_game *game, struct s_process *process)
{
	t_ind		offset;
	int			ret;

	read_arena(game->arena, process->pc + 1, (uint8_t*)&offset,
		sizeof(offset));
	change_end(&offset, sizeof(offset));
	offset %= IDX_MOD;
	ret = add_process(game->arena, process, offset, &game->processes);
	process->pc = mask_ptr(game->arena, process->pc + IND_SIZE + 1);
	return (ret);
}

int				lfork(struct s_game *game, struct s_process *process)
{
	t_ind		offset;
	int			ret;

	read_arena(game->arena, process->pc + 1, (uint8_t*)&offset,
		sizeof(offset));
	change_end(&offset, sizeof(offset));
	ret = add_process(game->arena, process, offset, &game->processes);
	process->pc = mask_ptr(game->arena, process->pc + IND_SIZE + 1);
	return (ret);
}

int				aff(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[16].argc];

	if (-1 == parse_and_validate_parameters(game, process, params))
		return (0);
	if (--params[0].param_val.val >= REG_NUMBER)
		return (0);
	params[0].param_val.val = process->registors[params[0].param_val.val];
	change_end(&params[0].param_val.val, REG_SIZE);
	params[0].param_val.val = params[0].param_val.val % 256;
	ft_jasprintf(&game->aff_out, "%c", (char)params[0].param_val.val);
	return (0);
}
