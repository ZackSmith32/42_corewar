/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:41:23 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/30 12:07:52 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds an 'element' to the beginning of the list.
*/

void	ft_lstadd(t_list **alst, t_list *element)
{
	if (!element || !alst)
		return ;
	element->next = *alst;
	*alst = element;
}
