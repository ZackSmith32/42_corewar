/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:48:08 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/19 19:52:58 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return the a pointer to the first non whitespace character
*/

char	*skip_whitespaces(char *line)
{
	if (line)
		while (ft_iswhitespace(*line))
			line++;
	return (line);
}
