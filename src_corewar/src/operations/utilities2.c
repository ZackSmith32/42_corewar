

#include <corewar.h>

int		check_registors(uint8_t op_code, struct s_parameter *params)
{	
	uint8_t		i;

	i = 0;
	while (i < g_op_tab[op_code].argc)
	{
		if ((params[i].param_type == T_REG)
			&& params[i].param_val.val >= REG_NUMBER)
			return (-1);
		i++;
	}
	return (0);
}