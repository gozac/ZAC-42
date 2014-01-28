# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 15:57:10 by ibakayok          #+#    #+#              #
#    Updated: 2014/01/19 21:32:47 by ibakayok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= wolf3d

FILES 		= add_coor.c \
			  compare.c \
			  ft_move.c \
			  ft_printf.c \
			  ft_putchar.c \
			  ft_putnbr.c \
			  ft_putstr.c \
			  ft_strlen.c \
			  get_next_line.c \
			  get_rad.c \
			  main.c \
			  mlx_pixel_img.c \
			  search.c \
			  stk_map.c \
			  wolf3d.c \

SRC			= $(addprefix src/, $(FILES))
OBJ			= $(SRC:src/%.c=.obj/%.o)
LIBMLX = -L/usr/X11/lib -lXext -lX11 -lmlx -L libft/ -lft
INCLUDE		= -I ./includes -I libft/includes

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
BL_COLOR=\x1b[30;01m
FN_COLOR=\x1b[34;01m
WARN_COLOR=\x1b[33;01m

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	@echo  "$(WARN_COLOR)---COMPILING---EXECUTABLE---"
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBMLX) -I ./includes
	@echo  "$(FN_COLOR)---COMPILATION COMPLETE---$(NO_COLOR)"

libft/libft.a:
	make -C libft/ fclean
	make -C libft/

.obj/%.o: src/%.c
		@mkdir -p .obj/
		@echo ".\c"
		@gcc $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf .obj/
	@/bin/rm -f libft/libft.a

fclean: clean
	@/bin/rm -f $(NAME)


re: fclean all


.PHONY: all fclean clean re
