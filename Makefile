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
COREWAR_DIR = ./src_corewar/
COREWAR_SRC = ./src_corewar/corewar

ASM = asm
ASM_DIR = ./src_asm/
ASM_SRC = ./src_asm/asm

all: $(COREWAR)

$(ASM): $(ASM_SRC)
	cp $< .

$(COREWAR): $(COREWAR_SRC)
	cp $< .

$(ASM_SRC): force
	$(MAKE) -C $(ASM_DIR)

$(COREWAR_SRC): force
	$(MAKE) -C $(COREWAR_DIR)

force:
	@true

clean:
	$(MAKE) fclean -C $(COREWAR_DIR)
	#$(MAKE) fclean -C $(ASM_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re