# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mburson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 19:31:26 by mburson           #+#    #+#              #
#    Updated: 2017/02/23 19:31:28 by mburson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

LIBFTPRINTF = 
LIBFTPRINTF_DIR = 

SRC = \
	$(addprefix ./src/, \

	)

OBJ = $(SRC:.c=.o)

HEADERS = -I ./src -I 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF)
	gcc $(CFLAGS) -o $@ $^

%.o: %.c
	gcc $(CFLAGS) $(HEADERS) -c -o $@ $<

$(LIBFTPRINTF): force
	cd $(LIBFTPRINTF_DIR) && $(MAKE)

force:
	@true

clean:
	rm -f $(OBJ)
	cd ./$(LIBFTPRINTF_DIR) && $(MAKE) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
