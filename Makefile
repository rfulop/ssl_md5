# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfulop <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 01:01:12 by rfulop            #+#    #+#              #
#    Updated: 2017/05/30 20:45:36 by rfulop           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = ft_ssl

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include
LIB_PATH = ./libft/

SRC_FILES = main.c \
			md5.c

INC_FILES = ft_ssl.h \

LIB_FILES = libft.a

OBJ_FILES = $(SRC_FILES:.c=.o)

OBJ_EXEC = $(addprefix $(OBJ_PATH),$(OBJ_FILES))

LIBFT = $(addprefix $(LIB_PATH),$(LIB_FILES))

all: $(NAME)

$(OBJ_PATH) :
	mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIB_PATH)includes
	echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

$(NAME) : $(OBJ_PATH) $(OBJ_EXEC)
	make -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(OBJ_EXEC) $(LIBFT) -o $@ -I $(INC_PATH) -I $(LIB_PATH)includes
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\032[32m created.\033[0m"

clean:
	rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJ_FILES)\033[1;0m\033[31m removed.\033[0m"
	make -C $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f resources/players/$(NAME)
	make -C $(LIB_PATH) fclean
	@echo "\033[31mLib \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all 

.PHONY: clean fclean
