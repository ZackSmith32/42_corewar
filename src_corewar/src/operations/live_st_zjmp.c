/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_st_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/06/15 12:47:59 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

#define LIVE_BYTE_SIZE 4

int		live(struct s_game *game, struct s_process *process)
{
	uint32_t	player_raw;
	uint32_t	player_name;

	read_arena(game->arena, process->pc + 1, (uint8_t*)&player_raw,
		LIVE_BYTE_SIZE);
	reverse_bytes((uint8_t*)&player_raw, sizeof(player_name),
			(uint8_t*)&player_name);
	player_name = ~player_name;
	game->lives += 1;
	process->called_live = true;
	if (player_name < game->champ_count)
	{
		game->last_live_champ = &game->champs[player_name];
		process->champ_index = player_name;
	}
	move_pc(game->arena, &process->pc, 5);
	return (0);
}

int		st(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[0x03].argc];
	uint8_t				*pc_og;
	union u_val			ind_offset;

	pc_og = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, params))
		return (0);
	if (-1 == check_registors(process->op_code, params))
		return (0);
	if (params[1].param_type == T_REG)
		process->registors[params[1].param_val.val - 1] =
			process->registors[params[0].param_val.val - 1];
	else if (params[1].param_type == T_IND)
	{
		reverse_bytes(params[1].param_val.arr, IND_SIZE, ind_offset.arr);
		game->last_write_index = process->champ_index;
		write_arena(game, pc_og + ((t_ind)ind_offset.val % IDX_MOD),
			(uint8_t *)&process->registors[params[0].param_val.val - 1],
			REG_SIZE);
	}
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
