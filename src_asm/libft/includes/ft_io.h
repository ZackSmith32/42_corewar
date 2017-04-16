/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:50:38 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/03 16:05:06 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <string.h>
# include <wchar.h>

/*
** math functions
*/

unsigned long long	ft_absolute(long long n);

/*
** string to integer conversion functions.
*/

unsigned long long	ft_atoull(const char *str);
unsigned long		ft_atoul(const char *str);
unsigned int		ft_atoui(const char *str);
long long			ft_atoll(const char *str);
long				ft_atol(const char *str);
int					ft_atoi(const char *str);

/*
** Functions to convert integers into strings.
*/

char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
char				*ft_ulltoa_base(unsigned long long n, int base, char h);

/*
** Functions that find the length of variables
*/

size_t				ft_ullsize_base(unsigned long long value,
					unsigned long long base);
size_t				ft_llsize_base(long long value, long long base, int sflag);
size_t				ft_wcslen(const wchar_t *wcs);
size_t				ft_wcsnlen(const wchar_t *wcs, size_t n);
size_t				ft_strlen(const char *str);

/*
** Functions that convert wide characters into multibyte arrays.
*/

size_t				ft_wcstombs(char *s, const wchar_t *wcs, size_t n);
int					ft_wctomb(char *s, wchar_t wc);

/*
** Functions that print wide characters as multibyte arrays.
*/

size_t				ft_putnwstr_fd(wint_t *wstr, size_t n, int fd);
wint_t				ft_putwchar_fd(wint_t wc, int fd);

/*
** Functions for printing non wide variable.
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putsbase_fd(long long n, long long base,
					int fd, char hex);
void				ft_putubase_fd(unsigned long long n,
					unsigned long long base, int fd, char hex);

#endif
