

#include <corewar.h>

int		check_registors(uint8_t op_code, struct s_parameter *params)
{	
	uint8_t		i;

	i = 0;
	// printf("op_code = %c\n", op_code);
	// printf("params.param_val.val = %lld\n", params[0].param_val.val);
	while (i < g_op_tab[op_code].argc)
	{
		if ((params[i].param_type == T_REG)
			&& params[i].param_val.val >= REG_NUMBER)
			return (-1);
		i++;
	}
	return (0);
}