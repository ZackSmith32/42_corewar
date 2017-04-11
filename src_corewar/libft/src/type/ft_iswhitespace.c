/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 13:15:15 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/25 13:20:20 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns 1 if the character is a whitespace character (\n,\f,\v,\t,\r," ")
** or 0 if it is not.
*/

int	ft_iswhitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}
