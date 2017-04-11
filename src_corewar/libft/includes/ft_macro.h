/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:38:54 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/03 16:00:50 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACRO_H
# define FT_MACRO_H

/*
**  Signed Min and Max values for different bit values.
*/

# define FT_S4_MIN -8
# define FT_S4_MAX 7
# define FT_S8_MIN -128
# define FT_S8_MAX 127
# define FT_S16_MIN -32768
# define FT_S16_MAX 32767
# define FT_S32_MIN -2147483648
# define FT_S32_MAX 2147483647
# define FT_S64_MIN (-9223372036854775807 - 1)
# define FT_S64_MAX 9223372036854775807

/*
**  Unsigned max values for different bit values.
*/

# define FT_U4_MAX 15U
# define FT_U8_MAX 255U
# define FT_U16_MAX 65535U
# define FT_U32_MAX 4294967295U
# define FT_U64_MAX 18446744073709551615U

/*
** The max and min for the different types (should be changed to the
** appropriate value based on the computer.)
*/

# define FT_CHAR_MIN FT_S8_MIN
# define FT_CHAR_MAX FT_S8_MAX
# define FT_UCHAR_MAX FT_U8_MAX
# define FT_SHRT_MIN FT_S16_MIN
# define FT_SHRT_MAX FT_S16_MAX
# define FT_USHRT_MAX FT_U16_MAX
# define FT_INT_MIN FT_S32_MIN
# define FT_INT_MAX FT_S32_MAX
# define FT_UINT_MAX FT_U32_MAX
# define FT_LONG_MIN FT_S64_MIN
# define FT_LONG_MAX FT_S64_MAX
# define FT_ULONG_MAX FT_U64_MAX
# define FT_LLONG_MIN FT_S64_MIN
# define FT_LLONG_MAX FT_S64_MAX
# define FT_ULLONG_MAX FT_U64_MAX

#endif
