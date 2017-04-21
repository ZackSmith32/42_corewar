/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:35:19 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/20 19:48:16 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_labelchar(char c)
{
	if (ft_islower(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}

/*
** Creates a duplicate of the label
*/

char	*dup_label(char	*src, t_parseinfo *pi)
{

}
