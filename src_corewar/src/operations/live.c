/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/16 19:00:30 by zsmith           ###   ########.fr       */
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

<<<<<<< HEAD
union			u_parameter
{
	uint8_t		reg[1];
	uint8_t		val[DIR_SIZE]
};
=======
/*
int		ld(sturct game *game, struct s_process *process)
{
	char			*pc;
	char			first_arg[REG_SIZE];
	// indirect offset only needs to hold the number of bytes to offset.  
	// it's possible for the user to set this value to any number of bytes
	// which is why I'm keeping this as a char with adjustable size
	char			indirect_offset[IND_SIZE];
	unsigned char	byte_count;
	unsigned int	parameter_encoding;

	pc = (char *)process->pc;
	byte_count = 1;
	parameter_encoding = (unsigned int)(pc + byte_count);
	byte_count += 5;
	
	// register: 1 byte
	if (parameter_encoding && 0x3 == 0x1)
		ft_memcpy(first_arg, )
	
	// direct: DIR_SIZE
	else if (parameter_encoding && 0x3 == 0x2)
		first_arg = ()

	// indirect: IND_SIZE
	else if (parameter_encoding && 0x3 == 0x3)
	{
		// get indirect offset
		ft_memcpy(indirect_offset, pc + byte_count, IND_SIZE);

		// convert indirect offset to a number
		// get memory at that address and return it.
		ft_memcpy(first_arg, (pc + convert_little_endian(indirect_offset, IND_SIZE)), REG_SIZE);
		byte_count += IND_SIZE
	}
	arg_direct = (char)(pc + 4)
	if (parameter_encoding)

}
*/
>>>>>>> 9aae049ed663071632d7b3dfc615e1919e415b24

int		ld(strct game *game, struct s_process *process)
{
	struct op_parameter	params[2];

	parse_parameters(game, process, params);
	ft_memmove(process->registors[(unit_8)args[1]->reg], (uint64)args[0]->val);



}
























