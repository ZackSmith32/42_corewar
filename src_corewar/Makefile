# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 19:31:26 by mburson           #+#    #+#              #
#    Updated: 2017/05/06 11:42:16 by kdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

INCLUDES = ../includes

SRC = \
	$(addprefix src/, \
		corewar.c \
		free.c \
		game_step.c \
		init_game_struct.c \
		op.c \
		utilites.c \
		$(addprefix args/, \
			parse_args.c \
			flags_tags.c \
			flags_tags2.c \
			args_utility.c \
		) \
		$(addprefix game_print/, \
			game_print.c \
			print_hex.c \
			print_process.c \
			keyhook.c \
			keyhook2.c \
		) \
		$(addprefix linked_list/, \
			lstadd.c \
			lstdel.c \
			lstdelone.c \
			lstiter.c \
			lstmap.c \
			lstnew.c \
			lstprint.c \
			lstpush.c \
			lstreverse.c \
			lstsort.c \
		) \
		$(addprefix operations/, \
			sti.c \
			add_sub.c \
			and_or_xor.c \
			fork_lfork_aff.c \
			utilites.c \
			utilities2.c \
			live_st_zjmp.c \
			ld_lld.c \
			ldi_lldi.c \
			move_one.c \
			validate_parameters.c \
			parse_parameters.c \
		) \
	) \

OBJ = $(SRC:.c=.o)

HEADERS = -I $(INCLUDES) -I ./libft/includes

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(CFLAGS) -o $@ $^ -lncurses

%.o: %.c
	gcc $(CFLAGS) $(HEADERS) -c -o $@ $<

$(OBJ): $(INCLUDES)/op.h $(INCLUDES)/corewar.h

$(LIBFT): force
	$(MAKE) -C $(LIBFT_DIR)

force:
	@true

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
