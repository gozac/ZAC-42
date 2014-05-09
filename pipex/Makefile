#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-segu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 16:46:57 by sde-segu          #+#    #+#              #
#    Updated: 2013/12/30 16:47:08 by sde-segu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all, clean, fclean, re

HEADER = pipex.h

NAME = pipex

FCT = main.c \
	ft_interpreteur.c \
	ft_execute.c \
	ft_search.c \
	ft_clean_path.c \
	ft_findpath.c

OBJ = $(FCT:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: lib $(NAME)

$(NAME): $(OBJ)
	 gcc $(FLAGS) -o $(NAME) $^ -L libft/ -lft

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< -I libft/includes/

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

lib:
	make -C libft/

re: fclean all

