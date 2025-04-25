# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 23:32:54 by mrocher           #+#    #+#              #
#    Updated: 2023/10/17 23:33:05 by mrocher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
GCC = cc
FLAGS = -Werror -Wextra -Wall
RM = rm -rf

SRC = ft_printf.c ft_print_tools.c ft_print_x.c ft_print_p.c ft_print_u.c ft_print_nbr.c

OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}

all : ${NAME}

clean: 
	${RM} ${OBJ}

fclean: clean
	$(RM) $(NAME)

re: fclean all