# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghubert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/14 16:45:36 by ghubert           #+#    #+#              #
#    Updated: 2017/03/02 19:48:15 by ghubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Fractol

SRC= ./srcs/main.c \
		./srcs/mandelbrot.c \
		./srcs/move.c \
		./srcs/events.c \

OBJ= ./main.o \
		./mandelbrot.o \
		./move.o \
		./events.o \

FLAGS= -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@make -C libft/
	@gcc -c $(FLAGS) -I ./includes/fractol.h $(SRC)
	@gcc $(OBJ) -o $(NAME) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[32m$(NAME) is now ready to go"

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@echo "\033[34mSuccessfully removed OBJ files"

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "\033[31mEverything is cleaned UP"

re: fclean all
