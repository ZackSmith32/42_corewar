/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:40:20 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/03 16:05:27 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memdup(const void *content, size_t content_size);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

void	*ft_memalloc(size_t size);
void	*ft_memrealloc(void *ptr, size_t new_size);
void	*ft_memreallocf(void *ptr, size_t new_size, size_t old_size);
void	*ft_memjoinf(void *s1, void *s2, size_t n1, size_t n2);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	ft_bzero(void *s, size_t n);
void	ft_memdel(void **ap);
void	ft_delgrid(void ***grid);
#endif
