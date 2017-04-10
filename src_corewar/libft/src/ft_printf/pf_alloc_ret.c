/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_alloc_ret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:13:01 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/07 16:13:34 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
** Return statement in the case that an allocation fails.
*/

int	pf_alloc_ret(int ret, char *s1, char *s2, char *s3)
{
	(s1 ? ft_memdel((void *)&s1) : 0);
	(s2 ? ft_memdel((void *)&s2) : 0);
	(s3 ? ft_memdel((void *)&s3) : 0);
	return (ret);
}
