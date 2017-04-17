/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/17 15:03:59 by zsmith           ###   ########.fr       */
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
	char			*pc;
	unsigned int	player_name;

	pc = (char *)process->pc;
	player_name = ~(unsigned int)(pc + 1);
	if (player_name > game->champ_count)
		return (-1);
	game->lives++;
	process->called_live = true;
	game->last_live_champ = &game->champs[player_name];
	move_pc(game->arena, &process->pc, 5);
	return (1);
}

/*
**	TODO: IND_SIZE is in the header, and in my interpretation up for adjustment
**		> what this means is that instead of being able to cast the value
**			we have to process the bits ourselves
*/

/*
**	TODO : what opperations need to do / what needs to be done before the operation 
**		1. identify if the encoding meets the operations requirements
**			> what happens if the encoding changes to something that is legit?
**			> what happens if the encoding isn't legit at the beginning?
**		2. store the total length of the operation and params
**		3. wait for countdown
**		*** After this is what the operation should do ***
**		4. validate the parameters again, I think against what they were to start
**		5. attempt to execute the operation, validating that parameters and encoding
**			are as expected, if not jump to next operation based on stored value from
**			pre computation of length.
*/

typedef uint16_t		t_indirect;
typedef uint32_t		t_register;
typedef uint32_t		t_direct;

union			u_val
{
	uint8_t		arr[sizeof(uint64_t)];
	uint64_t	val;
}

struct			s_parameter
{
	uint8_t		param_type;
	u_val		val; // TODO: discuss what size to make val
};

int				mod_params(uint8_t size, uint8_t *val, uint8_t mod_val)
{
	uint8_t		i;

	i = 0;
	while (i < size)
	{
		*val = *((uint64_t *)val) % mod_val;
		i++;
	}
	return (1);
}

int				mod_params(uint8_t size, uint8_t *val, uint8_t mod_val)
{
	uint64_t	temp;
	uint8_t		i;

	temp = *((uint64_t *)val) % mod_val;
	ft_memmove(val, &temp, DIR_SIZE);
	return (1);
}

/*
**	reutrn -1 when the parameters do not match the required formatting.
*/

int		ld(strct game *game, struct s_process *process)
{
	struct s_parameter	params[3]; // parse params doens't know how many params to get don't want to error out.

	if (-1 == parse_parameters(process, params))
		return (-1);
	if (params[2].param_type != 0) // check for only 2 parameters
		return (-1);
	if (!(params[0] == DIR_CODE || params[0] == IND_CODE)) // check param encoding
		return (-1);
	if (params[1] != REG_CODE) // check param encoding
		return (-1);
	
	params[0].val = *((uint64_t *)process[0].val) % IDX_MOD;

	ft_memmove(process->registors[(unit_8)args[1]->reg], (uint64)args[0]->val);



}
























