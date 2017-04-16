/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:55:07 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/02 14:03:53 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds a new 'element' to the end of a linked list.
*/

void	ft_lstadd_back(t_list **alst, t_list *element)
{
	t_list	*front;

	if (!element || !alst)
		return ;
	front = *alst;
	while (front->next)
		front = front->next;
	front->next = element;
}
