/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/13 21:10:28 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
/*
**	Live requirements:
**		x > update lives
**		x > update last_live_champ
**		x > move pc
*/

void	little_endian_to_big(char *ptr, int size)
{
	char	temp;
	int		start;
	int		end;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = ptr[start];
		ptr[start] = ptr[end];
		ptr[end] = temp;
		start++;
		end--;
	}
}

int		live(struct game *game, struct s_process *process)
{
	char			*pc;
	unsigned int	player_name;

	pc = (char *)process->pc;
	player_name = ~(unsigned int)(pc + 1);
	if (player_name > game->champ_count)
		return (-1);
	(game->champs[player_name]).lives++;
	game->last_live_champ = game->champs[player_name] 
	move_pc(&game->arena, &process->pc, 5);
	return (1);
}

/*
**	TODO: IND_SIZE is in the header, and in my interpretation up for adjustment
**		> what this means is that instead of being able to cast the value
**			we have to process the bits ourselves
*/

void	reverse_bytes(char *ptr, unsigned char size)
{
	unsigned char	len;
	unsigned char	i;
	char			*tmp;

	len = ft_strlen(ptr) - 1;
	tmp = ft_strdup(ptr);
	i = 0;
	len--;
	while (len >= 0)
	{
		len[i] = tmp[len];
		i++;
		len--;
	}
}


int		convert_little_endian(char *ptr, unsigned char size);
{
	unsigned char	byte_index;
	unsigned char	bit_index;
	unsigned char	power;
	unsigned int	num;

	// reverse_bytes(ptr, size)
	power = 0;
	i = 0;
	while (ptr[byte_index])
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			num += (ptr[i] & 128) * power;
			power = power * 2;
			bit_index++;
		}
		byte_index++;
	}
}

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

union			u_parameter
{
	uint8_t		reg[1];
	uint8_t		val[DIR_SIZE]
};

int		ld(strct game *game, struct s_process *process)
{
	struct op_parameter	params[2];

	parse_parameters(game, process, params);
	ft_memmove(process->registors[(unit_8)args[1]->reg], (uint64)args[0]->val);



}
























