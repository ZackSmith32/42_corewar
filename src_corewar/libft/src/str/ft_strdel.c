/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 10:08:49 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/24 10:22:55 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees the address of a string and sets its pointer to NULL.
*/

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}
