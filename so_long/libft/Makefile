# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 14:39:08 by mrocher           #+#    #+#              #
#    Updated: 2024/01/21 01:49:11 by mrocher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall 
RM = rm -rf

SRC = ft_atoi.c ft_bzero.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memset.c\
ft_putchar_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c\
ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_memmove.c ft_isalnum.c ft_calloc.c ft_strrchr.c ft_putendl_fd.c\
ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_strtrim.c ft_itoa.c ft_split.c ft_print_nbr.c ft_print_p.c ft_print_tools.c ft_print_u.c \
ft_print_x.c ft_printf.c ft_strcmp.c get_next_line.c ft_free_ptr.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(BONUS)

fclean:	clean
	$(RM) $(NAME)

bonus: $(OBJ) $(BONUS)
	ar rc $(NAME) $(OBJ) $(BONUS)

re: fclean all
