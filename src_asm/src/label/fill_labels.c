/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_labels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 20:18:03 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/26 16:31:46 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** find_label returns a pointer to the label with the same name as the key
*/

static t_label	*find_label(t_vec *labels, char *key)
{
	t_label	*ret;
	size_t	i;

	i = 0;
	while (i < labels->len)
	{
		ret = ft_vecindex(labels, i);
		if (ft_strcmp(key, ret->name) == 0)
			return (ret);
		i++;
	}
	return (NULL);
}

/*
** fill_labels will take a list of established labels and a list of label_calls
** and fill in the appropriate values into the output string.
*/

int				fill_labels(t_vec *labels, t_vec *label_calls, t_vec *output)
{
	t_label			*label;
	t_label_calls	*call;
	char			*byte_code;
	uintmax_t		value;
	size_t			i;

	i = 0;
	while (i < label_calls->len)
	{
		call = ft_vecindex(label_calls, i);
		if (!(label = find_label(labels, call->name)))
			return (print_error(11, call->name, call->addr));
		value = label->address - call->op_addr;
		if (!(byte_code = load_byte_code(value, call->size)))
			return (print_error(1, NULL, 0));
		ft_memmove(((char*)output->arr) + call->addr, byte_code, call->size);
		free(byte_code);
		i++;
	}
	return (0);
}
