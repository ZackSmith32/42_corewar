/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/17 22:27:49 by zsmith           ###   ########.fr       */
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
**	TODO : 
**		 : registers are little endian?
**		 : test what happens when the register is over written with an incorrect
**		 	value
*/

int		ld(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[2].argc]; // parse params doens't know how many params to get don't want to error out.
	uint8_t				byte_index;
	uint64_t			number_to_store;

	byte_index = 0;

	if (-1 == parse_and_validate_parameters(process, params, &byte_index))
		return (-1);

	number_to_store = params[0].param_val.val % IDX_MOD;

	if (params[1].param_val.val < REG_NUMBER)
		ft_memmove(process->registors[params[1].param_val.val], 
			number_to_store, REG_SIZE);
	else
		return (-1);
	
	printf("in : ld : move pc forward %d\n", byte_index);
	move_pc(game->arena, &process->pc, 5);
	return (0);
}














