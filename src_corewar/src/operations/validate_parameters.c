

#include <corewar.h>

/*
**	Validate that the parameter encoding byte is encoding the correct number of 
**		parameters for this oerartion.
*/
int				check_param_count(t_op op, char parameter_encoding)
{
	if ((parameter_encoding & 0x03) != 0 && op.argc == 3)
		return (-1);
	if ((parameter_encoding & 0x0f) != 0 && op.argc == 2)
		return (-1);
	if ((parameter_encoding & 0x3f) != 0 && op.argc == 1)
		return (-1);
	return (0);
}

/*
**	Validate that the parameter encoding byte matches the parameters that are 
**		alowed for this operation
*/
int				check_param_type(t_op op, char parameter_encoding)
{
	uint8_t		i;
	uint8_t		flag;

	i = 0;
	while (i < op.argc)
	{
		if ((parameter_encoding & 0xc0) == 0x40)
			flag = T_REG;
		else if ((parameter_encoding & 0xc0) == 0x80)
			flag = T_DIR;
		else if ((parameter_encoding & 0xc0) == 0xc0)
			flag = T_IND;
		if ((flag & op.arg_type[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

char		parse_and_validate_parameters(struct s_process *process, struct s_parameter *params)
{
	if (-1 == check_param_count(g_op_tab[process->op_code], *((process->pc) + 1)))
		return (-1);
	if (-1 == check_param_type(g_op_tab[process->op_code], *((process->pc) + 1)))
		return (-1);
	parse_parameters(process, params);
	return (0);
}
