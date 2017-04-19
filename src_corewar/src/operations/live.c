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
	game->last_live_champ = &game->champs[player_name];
	move_pc(game->arena, &process->pc, 5);
	return (0);
}

/*
**	TODO : x store everything in big endian, convert when necessary
**		 : x !! change what is being stored for indirect
**		 : x registers are big endian : because it's more right
**		 : test what happens when the register is over written with an incorrect
**		 	value
**			> depending on this we may be able to get rid of byte count
**		 : x do we need the union? a: yes.  storing register, not what is in the register
**		 : what about negative numbers?
*/

int8_t		ld(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[2].argc]; // parse params doens't know how many params to get don't want to error out.
	uint8_t				*pc_temp;
	uint8_t				reg;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, pc_temp, params, &byte_offset))
		return (-1);
	if (params[1].param_val.val < REG_NUMBER) //  should it be '<=' ?
		reg = params[1].param_val.val;
	else
		return (-1);
	if (params[0].param_type == T_DIR)
	{
		// ft_memmove_corewar(params[0].param_val.arr,
		// 	process->registors[reg], REG_SIZE);
	} 
	else if (params[0].param_type == T_IND)
	{
		// read_arena(params[0].param_val.val, IND_SIZE, &ind_offset);
		// ft_memmove_corewar(mask_ptr(process->pc, ind_offset),
		// 	process->registors[reg], REG_SIZE);
	}
	printf("in : ld : move pc forward %d\n", byte_offset);
	move_pc(game->arena, &process->pc, 5);
	return (0);
}

int8_t		st(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[3].argc]; 
	uint8_t				byte_offset;
	// uint64_t			number_to_store;

	byte_offset = 0;

	if (-1 == parse_and_validate_parameters(game, process, params, &byte_offset))
		return (-1);
	if (params[1].param_type == T_REG)
		process->registors[params[1].param_val.val] = params[1].param_val.val;
	if (params[1].param_type == T_IND)
		;
	return (0);
}













