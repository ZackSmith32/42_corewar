/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_relink_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 18:45:18 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/28 18:45:45 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Removes lst from the chain of linked lists and relinks the neighboring links
** in the list. SUCESSFULLY RELINKS!!
*/

void	*ft_relink_lst(t_list **head, t_list *lst)
{
	t_list	*prev;
	t_list	*after;

	if (!lst || !*head || !head)
		return (NULL);
	prev = *head;
	after = lst->next;
	if (prev == lst)
		*head = after;
	else
	{
		while (prev->next != lst && prev)
			prev = prev->next;
		prev->next = after;
	}
	ft_memdel(&(lst->content));
	lst->next = NULL;
	ft_memdel((void *)&lst);
	return (NULL);
}
