# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/03 19:31:45 by ibakayok          #+#    #+#              #
#    Updated: 2014/05/16 16:13:25 by ibakayok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= ft_minishell2

FILES 		= main.c \
			  lexeur.c \
			  parseur.c \
			  cd.c \
			  env.c \
			  findpath.c \
			  ft_execute.c \
			  ft_interpreteur.c \
			  search.c \
			  setenv.c \
			  pipe.c \
			  unsetenv.c \


SRC			= $(addprefix src/, $(FILES))
OBJ			= $(SRC:src/%.c=.obj/%.o)
INCLUDE		= -I ./includes -I libft/includes
LIBMLX 		= -L/usr/X11/lib -lXext -lX11 -lmlx -L libft/ -lft

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
BL_COLOR=\x1b[30;01m
FN_COLOR=\x1b[34;01m
WARN_COLOR=\x1b[33;01m

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBMLX)

start:
	@echo  "$(OK_COLOR)COMPILING-----EXE"
	@echo "\x1b[33;01m8\c"

libft/libft.a:
	@make -C libft/ fclean
	@make -C libft/

.obj/%.o: src/%.c
		@mkdir -p .obj/
		@echo "\x1b[33;01m=\c"
		@gcc $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf .obj/
	@make -C libft/ clean
	@/bin/rm -f libft/libft.a

fclean: clean
	@/bin/rm -f $(NAME)


re: fclean all


.PHONY: all fclean clean re
