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

COREWAR = corewar
COREWAR_SRC = ./src_corewar/corewar

ASM = asm
ASM_SRC = ./src_asm/asm

all: $(COREWAR)

$(ASM): $(ASM_SRC)
	cp $< .

$(COREWAR): $(COREWAR_SRC)
	cp $< .

$(ASM_SRC): force
	$(MAKE) -C ./src_asm

$(COREWAR_SRC): force
	$(MAKE) -C ./src_corewar

force:
	@true

clean:
	rm -f $(OBJ)
	cd ./$(LIBFTPRINTF_DIR) && $(MAKE) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re