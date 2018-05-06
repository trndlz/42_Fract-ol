# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 12:30:26 by tmervin           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2018/05/06 21:36:13 by tmervin          ###   ########.fr        #
=======
#    Updated: 2018/05/03 17:38:54 by tmervin          ###   ########.fr        #
>>>>>>> fb0516f9e3d6763e01fb9ec68cc92412d203293d
#                                                                              #
# **************************************************************************** #

NAME		:= fractol

SRC_PATH	:= ./src
SRC_NAME	:=	main.c			\
				keyboard.c		\
				keyboard2.c		\
				color.c			\
				fractales.c		\
				display.c		\
				init_colors.c	\
				images.c		\
				init.c

OBJ_PATH	:= ./src
CPPFLAGS	:= -Iincludes -I./libft/includes

LDFLAGS		:= -Llibft/
LDLIBS		:= -lft
MINILIBX	:= -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

CC			:= gcc -Werror -Wall -Wextra
OBJ_NAME	:= $(SRC_NAME:.c=.o)
SRC			:= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			:= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx_macos/
	$(CC) $(LDFLAGS) $(LDLIBS) $(MINILIBX) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null
	$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	make clean -C minilibx_macos/
	rm -fv $(NAME)

re: fclean all
