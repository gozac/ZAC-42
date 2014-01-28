# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 13:27:53 by ibakayok          #+#    #+#              #
#    Updated: 2014/01/12 17:57:52 by ibakayok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

SRC 		= ft_putstr.c \
			  ft_strlen.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isprint.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memccpy.c \
			  ft_memmove.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strdup.c \
			  ft_strcpy.c \
			  ft_strncpy.c \
			  ft_strcat.c \
			  ft_strncat.c \
			  ft_strlcat.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strcmp.c \
			  ft_strncmp.c \
			  ft_atoi.c \
			  ft_strstr.c \
			  ft_strnstr.c \
			  ft_memalloc.c \
			  ft_memdel.c \
			  ft_strnew.c \
			  ft_strdel.c \
			  ft_strclr.c \
			  ft_striter.c \
			  ft_striteri.c \
			  ft_strmap.c \
			  ft_strmapi.c \
			  ft_strequ.c \
			  ft_strnequ.c \
			  ft_strjoin.c \
			  ft_strsub.c \
			  ft_strtrim.c \
			  ft_strsplit.c \


OBJ 		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo  "\x1b[34;01m---COMPILATION COMPLETE---\x1b[0m"

$(OBJ):
	@echo  "\x1b[34;01m---COMPILING---LIB---"
	@gcc -Wall -Wextra -Werror -I includes -c $(SRC)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
