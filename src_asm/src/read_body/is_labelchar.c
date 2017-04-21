/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_labelchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:48:49 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/20 19:49:05 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	is_labelchar(char c)
{
	if (ft_islower(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}
