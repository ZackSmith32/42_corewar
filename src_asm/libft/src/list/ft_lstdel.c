/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:31:12 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/30 10:59:36 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Takes an address of a link's pointer and uses the function del to to free
** the contents of the list as well as the memory for every succesor.
** Then frees the link's pointer and sets it to null.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*delete;

	if (!alst || !*alst)
		return ;
	delete = *alst;
	if (delete->next)
		ft_lstdel(&delete->next, del);
	ft_lstdelone(alst, del);
}
