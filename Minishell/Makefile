# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/29 23:27:38 by ibakayok          #+#    #+#              #
#    Updated: 2013/12/29 23:34:47 by ibakayok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= ft_minishell1

SRC 		= get_next_line.c \
			  search.c \
			  setenv.c \
			  unsetenv.c \
			  main.c \
			  ft_interpreteur.c \
			  ft_execute.c \
			  ft_clean_path.c \
			  env.c \
			  cd.c \
			  built_in.c \

LIBMLX = -Ilibft/includes

FLAGS = -Wall -Wextra -Werror

all: lib $(NAME)

lib:
	make -C libft/ fclean
	make -C libft/


$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBMLX) -L libft/ -lft

clean:
	/bin/rm -f libft/libft.a

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


.PHONY: all fclean clean re
