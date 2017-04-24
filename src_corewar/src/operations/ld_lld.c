

#include <corewar.h>


int		ld(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[0x02].argc];
	uint8_t				*pc_temp;
	union u_val			ind_offset;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	modify_carry(process);
	if (-1 == check_registors(process->op_code, params))
	{
		process->pc = pc_temp;
		return (0);
	}
	if (params[0].param_type == T_DIR)
		process->registors[params[1].param_val.val] = params[0].param_val.val;
	else if (params[0].param_type == T_IND)
	{
		reverse_bytes(params[0].param_val.arr, IND_SIZE, ind_offset.arr);
		read_arena(game->arena, process->pc + (ind_offset.val % IDX_MOD), 
			(uint8_t *)&process->registors[params[1].param_val.val - 1],
			REG_SIZE);
	}
	process->pc = pc_temp;
	printf("in : ld : move pc forward %d\n", 4);
	return (0);
}

int		lld(struct s_game *game, struct s_process *process)
{
	struct s_parameter	params[g_op_tab[0x0d].argc];
	uint8_t				*pc_temp;
	union u_val			ind_offset;

	pc_temp = process->pc;
	if (-1 == parse_and_validate_parameters(game, process, &pc_temp, params))
		return (-1);
	modify_carry(process);
	if (-1 == check_registors(process->op_code, params))
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
	process->pc = pc_temp;
	return (0);
}
