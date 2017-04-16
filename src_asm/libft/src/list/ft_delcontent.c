/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delcontent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:06:29 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/07 13:15:13 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Function used to free the content of a list and set the size to be 0.
** Useful as the del function in ft_lstdelone and ft_lstdel.
*/

void	ft_delcontent(void *content, size_t content_size)
{
	free(content);
	(void)content_size;
}
