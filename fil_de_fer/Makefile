# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/22 20:09:07 by ibakayok          #+#    #+#              #
#    Updated: 2013/12/22 20:25:59 by ibakayok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf

SRC 		= get_next_line.c \
			  add_line.c \
			  rely_point.c \
			  make_grid.c \
			  main.c \
			  trace_seg.c \
			  is_good.c \
			  find.c \

LIBMLX = -L/usr/X11/lib -lXext -lX11 -lmlx

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
