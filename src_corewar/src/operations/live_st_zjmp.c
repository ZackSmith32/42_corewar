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
/*
**	Live requirements:
**		x > update lives
**		x > update last_live_champ
**		x > move pc
*/

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

/*
**	TODO
**		 : should we make pc a registor like it's supposed to be
**		 : indirects are variable size... should do a type def for them too?
**		 : x Need to not set pc in parameter parsing and set it after becaues we 
		 	are going to need pc
**		 : x store everything in big endian, convert when necessary
**		 : x !! change what is being stored for indirect
**		 : x registers are big endian : because it's more right
**		 : x test what happens when the register is over written with an incorrect
**		 	value
			> a: if the registers are out of bounds then continue the function as normal, 
			but don't load anything.  Kinda like if the carry was 1
**		 : x do we need the union? a: yes.  storing register, not what is in the register
**		 : what about negative numbers?
**		 : might need to call parse parameters in step fucntion because if they are not
**		 	valid then do we still wait for the countdown
*/

/*
**	Note:
**		> when parse_and_validate returns -1 that means operation encoding did not match 
**			operations prototype.  PC += 1
**		> if register number exceeds max registers, then wait till end of countdown, and 
**			then move PC to next operation
**		> registers are zero based, so add a '- 1' when searching for a register index
**			> this is confirmed by zord which calls r1 for its name.
**		> the "val" in the params is big endian.
**			> registers are big endian, but since they are 1 byte it don't matter
*/



/*
**	TEST:
**		> test if registors exceed max registor
*/
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
		process->registors[params[1].param_val.val] = 
			process->registors[params[0].param_val.val];
	else if (params[1].param_type == T_IND)
	{
		reverse_bytes(params[1].param_val.arr, IND_SIZE, ind_offset.arr);
		write_arena(game->arena, process->pc + ind_offset.val, 
			(uint8_t *)&process->registors[params[0].param_val.val], REG_SIZE);
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












