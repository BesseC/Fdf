# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbesse <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 14:23:18 by cbesse            #+#    #+#              #
#    Updated: 2018/03/13 18:05:43 by cbesse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf
SRC = main.c lecture.c grille.c convert.c coleur.c grilleiso.c scaling.c ligne.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Werror -Wextra
LIB = -Llibft -lft -lmlx

all : $(NAME)

$(NAME) : $(OBJ)
	@cd libft && make
	@cd minilibx_macos && make
	@$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIB) -framework OpenGL -framework Appkit
	@echo "Compilation termine"

%.o : %.c
	@echo "\033[0;36m\033[1ACompilation de $@\033[0m"
	@$(CC) $(FLAGS) -c $<

clean :
	@rm -rf $(OBJ)
	@cd libft && make clean
	@cd minilibx_macos && make clean
	@echo "\033[1;32mSuppresion des objets ternime\033[0m"

fclean : clean
	@rm -rf $(NAME) $(LIB)
	@cd libft && make fclean
	@echo "\033[1;32mSuppresion de la librairie\033[0m"

re : fclean all
