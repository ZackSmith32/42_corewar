# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 09:50:14 by kdavis            #+#    #+#              #
#    Updated: 2017/03/15 16:41:10 by kdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

SUBDIR			= memory list gnl leftovers type str ft_io ft_printf matrix
SUBDIR			+=vector

MEMORY			=ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c
MEMORY			+=ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_memdup.c
MEMORY			+=ft_memrealloc.c ft_memreallocf.c ft_memjoinf.c ft_delgrid.c

GNL				=get_next_line.c ft_getint_base.c

TYPE			=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c
TYPE			+=ft_iswhitespace.c ft_isprint.c ft_toupper.c ft_tolower.c
TYPE			+=ft_isupper.c ft_islower.c

STR				=ft_strdup.c ft_strcpy.c ft_strctchr.c ft_strctrim.c
STR				+=ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c
STR				+=ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c
STR				+=ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_strrev.c
STR				+=ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strsub.c
STR				+=ft_strchrrmv.c ft_strndup.c ft_strnequ.c ft_strjoin.c
STR				+=ft_strtrim.c ft_strsplit.c ft_splcount.c ft_strvgrow.c
STR				+=ft_strfcount.c

FT_IO			=ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c
FT_IO			+=ft_putnbr_fd.c ft_putchar.c ft_putstr.c ft_putendl.c
FT_IO			+=ft_putsbase_fd.c ft_putubase_fd.c
FT_IO			+=ft_ullsize_base.c ft_llsize_base.c ft_putwchar_fd.c
FT_IO			+=ft_putnwstr_fd.c ft_wctomb.c ft_wcstombs.c ft_wcslen.c
FT_IO			+=ft_wcsnlen.c ft_atoi.c ft_absolute.c ft_atoll.c ft_atol.c
FT_IO			+=ft_atoull.c ft_atoul.c ft_atoui.c ft_strlen.c ft_itoa.c
FT_IO			+=ft_ulltoa_base.c ft_itoa_base.c

FT_PRINTF		=ft_asprintf.c ft_printf.c ft_vdprintf.c pf_append_data.c
FT_PRINTF		+=pf_flag_reader.c pf_nbr_funcs.c ft_dprintf.c ft_vasprintf.c
FT_PRINTF		+=pf_alloc_ret.c pf_funcarray.c pf_str_funcs.c

LEFTOVERS		=ft_new_handle.c
LEFTOVERS		+=ft_power.c ft_negflag.c 
LEFTOVERS		+=ft_bitstoa.c ft_putbits.c ft_xorswap.c

MATRIX			=ftmx_id.c ftmx_scale.c ftmx_translate.c ftmx_mult.c

VECTOR			=ft_initialize_vec.c ft_grow_vec.c ft_vecapp.c

FILENAMES		=$(addprefix memory/, $(MEMORY))
FILENAMES		+=$(addprefix gnl/, $(GNL))
FILENAMES		+=$(addprefix ft_io/, $(FT_IO))
FILENAMES		+=$(addprefix leftovers/, $(LEFTOVERS))
FILENAMES		+=$(addprefix type/, $(TYPE))
FILENAMES		+=$(addprefix str/, $(STR))
FILENAMES		+=$(addprefix ft_printf/, $(FT_PRINTF))
FILENAMES		+=$(addprefix matrix/, $(MATRIX))
FILENAMES		+=$(addprefix vector/, $(VECTOR))

SRC				=$(addprefix src/,$(FILENAMES))
BUILD			=$(addprefix build/, $(FILENAMES:.c=.o))
BUILDIR			=$(addprefix build/,$(SUBDIR))
CFLAGS			=-Wall -Wextra -Werror -I includes/
CC				= gcc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC) | $(BUILD) 
	ar -rcs $@ $(BUILD)

build/%.o: src/%.c | build
		$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf build/

fclean: clean
	rm -rf $(NAME)

re: fclean all

build:
	mkdir build/ 
	mkdir -p $(BUILDIR)
