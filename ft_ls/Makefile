# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/15 16:48:24 by ibakayok          #+#    #+#              #
#    Updated: 2014/04/20 20:59:05 by ibakayok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= ft_ls

FILES 		= main.c \
			  get_option.c \
			  list_dir.c \
			  get_stat.c \


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
