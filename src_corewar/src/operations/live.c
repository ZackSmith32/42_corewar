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
	player_name = ~(unsigned int)(pc + 1);

	game->lives++;
	process->called_live = true;
	if (player_name < game->champ_count)
		game->last_live_champ = &game->champs[player_name];
	move_pc(game->arena, &process->pc, 5);
	return (0);
}

/*
**	TODO
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


int		ld(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[2].argc];
	uint8_t				*pc_temp;
	union u_val			ind_offset;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	process->pc = pc_temp;
	if (!(params[1].param_val.val < REG_NUMBER))
		return (0);
	if (params[0].param_type == T_DIR)
		process->registors[params[1].param_val.val] = params[0].param_val.val;
	else if (params[0].param_type == T_IND)
	{
		reverse_bytes(params[0].param_val.arr, IND_SIZE, ind_offset.arr);
		read_arena(game->arena, process->pc + ind_offset.val, 
			(uint8_t *)&process->registors[params[1].param_val.val - 1],
			REG_SIZE);
	}
	printf("in : ld : move pc forward %d\n", 4);
	return (0);
}

int8_t		st(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[3].argc];
		uint8_t				*pc_temp;
	uint8_t				byte_offset;
	union u_val			ind_offset;
	// uint64_t			number_to_store;

	byte_offset = 0;

	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	if (params[1].param_type == T_REG)
		process->registors[params[1].param_val.val] = 
			process->registors[params[0].param_val.val];
	if (params[1].param_type == T_IND)
	{
		reverse_bytes(params[1].param_val.arr, IND_SIZE, ind_offset.arr);
		write_arena(game->arena, process->pc + ind_offset.val, 
			(uint8_t *)&process->registors[params[0].param_val.val], REG_SIZE);
	}
	return (0);
}













