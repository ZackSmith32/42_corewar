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

ASM = asm

COREWAR = corewar


COREWAR_SRC = ./corewar/corewar

ASM_SRC = ./asm/asm

all: $(ASM) $(COREWAR)

$(ASM): $(ASM_SRC)
    cp @< .

$(COREWAR): $(COREWAR_SRC)
    cp @< .

$(ASM_SRC): force
    $(MAKE) -C ./asm

$(COREWAR_SRC): force
    $(MAKE) -C ./corewar

force:
	@true

clean:
	rm -f $(OBJ)
	cd ./$(LIBFTPRINTF_DIR) && $(MAKE) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re