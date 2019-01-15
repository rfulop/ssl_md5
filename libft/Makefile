# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/29 03:17:34 by rfulop            #+#    #+#              #
#    Updated: 2018/01/13 08:19:10 by rfulop           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

CFLAGS = -g -Wall -Werror -Wextra

CPPFLAGS = -I./includes

SRC_PATH = ./

OBJ_PATH = obj/

SRC_ARRAY = ft_intclr.c \
			ft_intfill.c \

SRC_CHAR = ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \

SRC_CONV = ft_conv_hex.c \
			ft_conv_oct.c \
			ft_convert_base.c \
			ft_itoa_base.c \
			ft_itoa_ll.c \
			ft_itoa_ull.c \
			ft_itoa.c \

SRC_IO = ft_putchar_fd.c \
			ft_putchar.c \
			ft_putendl_fd.c \
			ft_putendl.c \
			ft_putlong.c \
			ft_putnbr_fd.c \
			ft_putnbr.c \
			ft_putstr_fd.c \
			ft_putstr.c \
			get_next_line.c \

SRC_LST =  ft_lstnew.c \
 			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \

SRC_MATHS = ft_atoi_ll.c \
			ft_atoi.c \
			ft_power.c \

SRC_MEM = ft_bzero.c \
			ft_memset.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \

SRC_STR =   ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strncpy.c \
			ft_strnstr.c \
			ft_strsplit.c \
			ft_lstmap.c \
			ft_strndup.c \
			ft_strnjoin.c \
			ft_findstr.c \
			ft_stradd.c \

SRC_PRINTF= ft_printf.c \
		   ft_b.c \
		   ft_c.c \
		   ft_d.c \
		   ft_o.c \
		   ft_p.c \
		   ft_s.c \
		   ft_u.c \
		   ft_x.c \
		   ft_flag.c \
		   ft_init_opt.c \
		   ft_print_xou.c \
		   ft_conv_type.c \
		   ft_jz.c \
		   ft_cast.c \
		   ft_cast_d.c \
		   ft_prec.c \
		   ft_width.c \
		   ft_unicode.c \

OBJ_ARRAY = $(addprefix ${OBJ_PATH}/, $(SRC_ARRAY:.c=.o))
OBJ_CHAR = $(addprefix ${OBJ_PATH}/, $(SRC_CHAR:.c=.o))
OBJ_CONV = $(addprefix ${OBJ_PATH}/, $(SRC_CONV:.c=.o))
OBJ_IO = $(addprefix ${OBJ_PATH}/, $(SRC_IO:.c=.o))
OBJ_LST = $(addprefix ${OBJ_PATH}/, $(SRC_LST:.c=.o))
OBJ_MATHS = $(addprefix ${OBJ_PATH}/, $(SRC_MATHS:.c=.o))
OBJ_MEM = $(addprefix ${OBJ_PATH}/, $(SRC_MEM:.c=.o))
OBJ_STR = $(addprefix ${OBJ_PATH}/, $(SRC_STR:.c=.o))
OBJ_PRINTF = $(addprefix ${OBJ_PATH}/, $(SRC_PRINTF:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_ARRAY) $(OBJ_CHAR) $(OBJ_CONV) $(OBJ_IO) $(OBJ_LST) $(OBJ_MATHS) $(OBJ_MEM) $(OBJ_STR) $(OBJ_PRINTF)
	@echo "\033[37mLinking...\033[0m"
	@ar rc $(NAME) $(OBJ_ARRAY) $(OBJ_CHAR) $(OBJ_CONV) $(OBJ_IO) $(OBJ_LST) $(OBJ_MATHS) $(OBJ_MEM) $(OBJ_STR) $(OBJ_PRINTF)
	@ranlib $(NAME)
	@echo "\033[32mLibrary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"


$(OBJ_PATH)%.o: ./ft_array/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

$(OBJ_PATH)%.o: ./ft_char/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

$(OBJ_PATH)%.o: ./ft_conv/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

$(OBJ_PATH)%.o: ./ft_io/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

$(OBJ_PATH)%.o: ./ft_lst/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

$(OBJ_PATH)%.o: ./ft_maths/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

$(OBJ_PATH)%.o: ./ft_mem/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"
$(OBJ_PATH)%.o: ./ft_str/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"
$(OBJ_PATH)%.o: ./ft_printf/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJ_NAME)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@rm -fv $(NAME)
	@echo "\033[31mLib \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
