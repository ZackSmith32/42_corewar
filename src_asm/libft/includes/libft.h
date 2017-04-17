/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:10:08 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/03 15:50:34 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <ft_string.h>
# include <ft_type.h>
# include <ft_io.h>
# include <ft_macro.h>
# include <ft_matrix.h>
# include <ft_printf.h>
# include <ft_list.h>
# include <ft_memory.h>
# include <get_next_line.h>

char				*ft_bitstoa(unsigned long long block, int bit_size);
void				ft_putbits(unsigned long long block, int bit_size);

char				*ft_itoa_base(int n, int base);
char				*ft_itoa(int n);

unsigned long long	ft_power(unsigned long long nbr, int power);

void				ft_xorswapi(int *a, int *b);
void				ft_negflag(int *n, int *neg);

#endif
