/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 18:16:43 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/28 18:53:51 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**delete_array(char **array)
{
	size_t	i;

	i = 0;
	if (array)
	{
		while (array[i])
			ft_memdel((void*)&array[i++]);
		ft_memdel((void*)&array);
	}
	return (NULL);
}

/*
** Allocates and returns an array of strings (all null terminated, including
** the array itself) obtained by splitting string s by using character c as a
** delimiter.
*/

char		**ft_strsplit(char const *s, char c)
{
	char			**r;
	size_t			word_len;
	size_t			word_count;
	unsigned int	result_index;

	if (!s)
		return (NULL);
	word_count = ft_splcount(s, c, ft_strlen(s));
	if (!(r = (char**)ft_memalloc(sizeof(char*) * (word_count + 1))))
		return (NULL);
	result_index = 0;
	while (word_count > 0)
	{
		word_len = 0;
		while (*s == c)
			s++;
		while (s[word_len] != c && s[word_len])
			word_len++;
		if (!(r[result_index++] = ft_strndup(s, word_len)))
			return (delete_array(r));
		s += word_len;
		word_count -= 1;
	}
	return (r);
}
