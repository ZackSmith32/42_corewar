/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:00:48 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/31 11:05:01 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates a fresh link. Initialize the content of the link by making copies
** of the parameters. If parameter content=NULL then variable content=NULL and
** variable content_size will be 0. Next is initalized to NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;
	void	*copycont;

	if (!(link = ft_memalloc(sizeof(*link))))
		return (NULL);
	if (!content)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		if (!(copycont = ft_memdup(content, content_size)))
		{
			ft_memdel((void *)&link);
			return (NULL);
		}
		link->content = copycont;
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}
