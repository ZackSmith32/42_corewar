# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mburson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 19:31:26 by mburson           #+#    #+#              #
#    Updated: 2017/04/15 20:05:09 by kdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

MAKE = make

FILES = asm.c\
		asm_error.c

SRC	= $(addprefix src/, $(FILES))
OBJ = $(addprefix build/, $(FILES:.c=.o))
LIB = libft

IFLAGS = -I libft/includes -I ../includes 
LFLAGS	= -L $(LIB) -lft
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIB)/$(LIB).a
	gcc $(CFLAGS) -o $@ $^

build/%.o: src/%.c | build
	gcc $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIB)/$(LIB).a: force
	$(MAKE) -C $(LIB)

force:
	@true

build:
	mkdir build/

clean:
	rm -f build
	$(MAKE) -C $(LIB) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
