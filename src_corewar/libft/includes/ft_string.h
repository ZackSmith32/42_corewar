/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:02:46 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/25 12:18:16 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <string.h>
# include <ft_io.h>
# include <ft_vector.h>
# include <ft_memory.h>

typedef struct	s_strvec
{
	char		*str;
	size_t		len;
	size_t		size;
}				t_strvec;

size_t			ft_strvgrow(t_strvec *self, size_t index);

char			**ft_strsplit(char const *s, char c);

char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *b, const char *l, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1);
char			*ft_strrev(char	*str);
char			*ft_strchrrmv(char *str, char c);
char			*ft_strctrim(char *str, char c);

size_t			ft_strlcat(char *dst, const char *str, size_t size);

unsigned int	ft_splcount(const void *v, char c, size_t len);
unsigned int	ft_strfcount(const char *s, int (*dchar)(int));

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strctchr(char *str, char c);

void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif
