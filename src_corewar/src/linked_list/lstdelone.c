/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:35:37 by mburson           #+#    #+#             */
/*   Updated: 2016/12/04 16:35:38 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

void	lstdelone(t_list **alst, void (*del)(void*))
{
	t_list	*swap;

	swap = (*alst)->next;
	if (*alst)
		del((*alst)->content);
	free(*alst);
	*alst = swap;
}
