/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/12 09:50:18 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Live requirements:
**		x > update lives
**		x > update last_live_champ
**		x > move pc
*/

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
**	TODO: What is INDEX_MOD?
**		: How do we want to deal with processing numbers with unknown size?
*/

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
	if (parameter_encoding >> 30 == 0x1)
		ft_memcpy(first_arg, )
	
	// direct: DIR_SIZE
	else if (parameter_encoding >> 30 == 0x2)
		first_arg = ()

	// indirect: IND_SIZE
	else if (parameter_encoding >> 30 == 0x3)
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

/*
unsigned long long	convert_binary_to_long_long(char *ptr, unsigned char size);

char			valid_param_encoding();
// will be spefic for each

unsigned char	get_argument(void *pc, char arg_number, unsigned char *bytes_read, );

*/




























