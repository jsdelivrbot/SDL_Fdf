# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 11:31:17 by cpieri            #+#    #+#              #
#    Updated: 2018/03/09 14:15:24 by cpieri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

FRAME	=	-L./minilibx -lmlx -framework OpenGl -framework AppKit

CPPFLAGS=	-Iinclude

FLAGSFT	=	-L./libft -lft

SRC_PATH=	src

OBJ_PATH=	obj

SRC_NAME=	main.c		\
			bresenham.c	\
			parse.c		\
			maps.c		\
			img.c			\
			event3.c	\
			event2.c	\
			exit.c

OBJ_NAME=	$(SRC_NAME:.c=.o)

SRC		=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ		=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

L_SDL	=	$(shell pkg-config --libs sdl2)

I_SDL	= 	$(shell pkg-config --cflags sdl2)

.PHONY:	all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS) $(FLAGSFT) $(I_SDL) $(L_SDL)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
			@mkdir $(OBJ_PATH) 2> /dev/null || true
			@$(CC) $(CFLAGS) $(CPPFLAGS) $(I_SDL) -o $@ -c $<

clean:
			@echo "cleaning"
			@make clean -C ./libft/
			@/bin/rm -f $(OBJ)
			@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:		clean
			@make fclean -C ./libft/
			@/bin/rm -f $(NAME)

re:			fclean all
