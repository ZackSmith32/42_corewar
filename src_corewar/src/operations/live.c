/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:51:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/13 14:58:11 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
**	TODO: What is INDEX_MOD?
**		: How do we want to deal with processing numbers with unknown size?
*/

struct	op_parameter
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

/*
unsigned long long	convert_binary_to_long_long(char *ptr, unsigned char size);

char			valid_param_encoding();
// will be spefic for each

unsigned char	get_argument(void *pc, char arg_number, unsigned char *bytes_read, );




if (parameter_encoding && 0x3 == 0x1)
	{
		read_vm(pc + byte_count, 1, first_arg);
		byte_count += 1;
	}
	
	// direct: DIR_SIZE
	else if (parameter_encoding && 0x3 == 0x2)
	{
		read_vm(pc + byte_count, DIR_SIZE, first_arg);
		byte_count += DIR_SIZE;
	}

	// indirect: IND_SIZE
	else if (parameter_encoding && 0x3 == 0x3)
	{
		read_vm(pc + byte_count, IND_SIZE, arg_offset);
		read_vm(pc + (uint64_t)art_offset, REG_SIZE, first_arg);
		byte_count += IND_SIZE;
	}

*/























