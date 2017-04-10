/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:50:03 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/17 09:16:44 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Takes in a string and reverses it.
*/

char	*ft_strrev(char *str)
{
	char	*tail;
	char	*head;
	char	temp;

	if (!str)
		return (NULL);
	head = str;
	tail = str + ft_strlen(str) - 1;
	while (tail > head)
	{
		temp = *head;
		*head++ = *tail;
		*tail-- = temp;
	}
	return (str);
}
