/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:09:49 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/30 08:58:42 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Takes an address of a link's pointer and uses the function del to to free
** the contents of the list. Then frees the link's pointer and sets it to null.
** NOTE: Does not free next.
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*delete;

	if (!alst || !*alst)
		return ;
	delete = *alst;
	del(delete->content, delete->content_size);
	free(*alst);
	*alst = NULL;
}
