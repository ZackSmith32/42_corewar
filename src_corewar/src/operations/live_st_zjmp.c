/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/17 23:11:04 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		live(struct s_game *game, struct s_process *process)
{
	uint8_t			*pc;
	unsigned int	player_name;

	pc = process->pc;
	player_name = ~(*(unsigned int *)(pc + 1));
	game->lives++;
	process->called_live = true;
	if (player_name < game->champ_count)
		game->last_live_champ = &game->champs[player_name];
	move_pc(game->arena, &process->pc, 5);
	return (0);
}

int		st(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[0x03].argc];
	uint8_t				*pc_temp;
	union u_val			ind_offset;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	if (-1 == check_registors(process->op_code, params))
	{
		process->pc = pc_temp;
		return (0);
	}
	if (params[1].param_type == T_REG)
		process->registors[params[1].param_val.val - 1] =
			process->registors[params[0].param_val.val - 1];
	else if (params[1].param_type == T_IND)
	{
		reverse_bytes(params[1].param_val.arr, IND_SIZE, ind_offset.arr);
		write_arena(game->arena, process->pc +((t_ind)ind_offset.val % IDX_MOD),
			(uint8_t *)&process->registors[params[0].param_val.val - 1],
			REG_SIZE);
	}
	process->pc = pc_temp;
	return (0);
}

int		zjmp(struct s_game *game, struct s_process *process)
{
	t_ind			ind_offset;

	if (1 == process->carry)
	{
		read_arena(game->arena, process->pc + 1, (uint8_t *)&ind_offset,
			IND_SIZE);
		change_end(&ind_offset, IND_SIZE);
		ind_offset = ind_offset % IDX_MOD;
		process->pc = mask_ptr(game->arena, process->pc + ind_offset);
	}
	else
		process->pc = mask_ptr(game->arena, process->pc + 1 + IND_SIZE);
	return (0);
}
