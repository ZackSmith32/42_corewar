/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:45:05 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/29 20:18:16 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each element in the list.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst && f)
	{
		f(lst);
		lst = lst->next;
	}
}
