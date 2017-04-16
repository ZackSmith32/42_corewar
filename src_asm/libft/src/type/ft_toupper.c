/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:23:25 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 10:29:16 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** If c is a lower case alphabetical character it is converted to upper case.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
