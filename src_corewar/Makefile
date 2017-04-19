# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 19:31:26 by mburson           #+#    #+#              #
#    Updated: 2017/04/17 17:44:45 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

SRC = \
	$(addprefix src/, \
		corewar.c \
		free.c \
		init_game_struct.c \
		$(addprefix flags/, \
			parse_args.c \
			flags_tags.c \
			flags_usage.c \
		) \
		op.c \
		$(addprefix game_print/, \
			game_print.c \
			print_hex.c \
		) \
		$(addprefix game_step/, \
			game_step.c \
		) \
		$(addprefix operations/, \
			utilites.c \
			live.c \
			validate_parameters.c \
			parse_parameters.c \
		) \
	) \
	$(addprefix maxlib/list/, \
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
	)

OBJ = $(SRC:.c=.o)

HEADERS = -I ../includes -I ./libft/includes

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(CFLAGS) -o $@ $^

%.o: %.c
	gcc $(CFLAGS) $(HEADERS) -c -o $@ $<

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
