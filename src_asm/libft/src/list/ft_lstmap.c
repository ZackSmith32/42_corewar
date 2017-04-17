/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:48:02 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/07 13:19:34 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Iterates a list and applies the function f resulting in a fresh list
** generated from the successive application of f. If an allocation fails
** return NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*tail;

	if (!lst || !f)
		return (NULL);
	if (!(map = f(lst)))
		return (NULL);
	lst = lst->next;
	tail = map;
	while (lst)
	{
		if (!(tail->next = f(lst)))
		{
			ft_lstdel(&map, ft_delcontent);
			return (NULL);
		}
		tail = tail->next;
		lst = lst->next;
	}
	return (map);
}
