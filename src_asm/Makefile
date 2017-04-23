# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mburson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 19:31:26 by mburson           #+#    #+#              #
#    Updated: 2017/04/22 18:17:57 by kdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= asm

MAKE	= make

SUBDIR	=	read_header line_parsing error read_body op label

FILES	=	asm.c\
			endian_switch.c\
			$(addprefix op/,\
				search.c\
				parse.c\
				write.c\
			)\
			$(addprefix label/,\
				search.c\
				parse.c\
				new.c\
				dup.c\
			)\
			$(addprefix read_header/,\
				read_header.c\
				read_commands.c\
			)\
			$(addprefix read_body/,\
				parse_line.c\
				read_body.c\
			)\
			$(addprefix line_parsing/,\
				is_labelchar.c\
				next_token.c\
				skip_space_rev.c\
				skip_whitespaces.c)\
			$(addprefix error/,\
				asm_error.c)\
			op.c\

SRC		= $(addprefix src/, $(FILES))
OBJ		= $(addprefix build/, $(FILES:.c=.o))
OBJDIR	= $(addprefix build/, $(SUBDIR))
LIB		= libft

IFLAGS	= -I libft/includes -I ../includes 
LFLAGS	= -L $(LIB) -lft
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

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
	mkdir -p $(OBJDIR)

clean:
	rm -rf build
	$(MAKE) -C $(LIB) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
