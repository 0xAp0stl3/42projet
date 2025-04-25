# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 16:25:22 by mrocher           #+#    #+#              #
#    Updated: 2024/01/25 15:22:20 by mrocher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC 				= gcc
CFLAGS			= -Wall -Werror -Wextra
FILE_EXTENSION	= .c

SRCS			= ft_algo.c ft_check.c ft_find.c ft_part.c ft_push.c ft_swap.c \
				ft_rotate.c ft_reverse_rotate.c ft_sort_small.c ft_utils.c ft_move.c

MAIN			= push_swap.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

SHELL 				:= /bin/bash

SRCS_PATH			= $(CURDIR)

OBJS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})
OBJ_MAIN			= $(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.o})

# Couleurs
RED 		= \\033[0;31m
GREEN 		= \\033[0;32m
YELLOW 		= \\033[0;33m
BLUE 		= \\033[0;34m
MAGENTA 	= \\033[0;35m
CYAN 		= \\033[0;36m
WHITE 		= \\033[0;37m
RESET 		= \\033[0m

all:		start $(NAME) end

start:
			@printf "%b" "$(GREEN)"
			@echo "+-----------------------+"
			@echo "|	       		|"
			@echo "|	$(NAME)	|"
			@echo "|	       		|"
			@echo "+-----------------------+"
			@echo "-------------------------"
			
libft:
			@make -C libft > /dev/null

$(NAME):	${OBJS} ${OBJ_MAIN} libft
			@($(CC) $(CFLAGS) -o $@ ${OBJS} ${OBJ_MAIN} -Llibft -lft)

objs/%.o: 	$(SRCS_PATH)/%.c
			@mkdir -p $(dir $@)
			@printf "$(GREEN)Compiling %-*s$(RESET)" 20 "$(notdir $<)"
			@$(CC) $(CFLAGS) -c $< -o $@ && printf "$(GREEN) [OK]$(RESET)\n" || printf "$(RED) [FAILED]$(RESET)\n"

end:
			@printf "%b" "$(GREEN)"
			@printf "%b" "$(GREEN)Compilation success$(RESET)\n"
			@printf "%b" "$(GREEN)-------------------------$(RESET)\n"
			@printf "%b" "$(GREEN)push_swap [OK]$(RESET)\n"

clean:
			@rm -rf objs libft/*.o
			@printf "%b" "$(RED)DELETE objs$(RESET)\n"
			
fclean:		clean
			@rm -rf $(NAME)
			@printf "%b" "$(RED)DELETE $(NAME)$(RESET)\n"
			
re:			fclean all

.PHONY:		all clean fclean re start end