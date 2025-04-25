# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 21:34:09 by mrocher           #+#    #+#              #
#    Updated: 2024/01/22 19:01:47 by mrocher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
CC 				= clang
CFLAGS			= -Wall -Werror -Wextra
FILE_EXTENSION	= .c

SRCS			= ft_free.c ft_input.c ft_init.c ft_checkmap.c ft_utils.c ft_render.c ft_map.c \
				ft_valided.c
#SRCS_BONUS		= 

MAIN			= so_long.c
#MAIN_BONUS		= 

################################################################################
#                                  Makefile  objs                              #
################################################################################

SHELL 				:= /bin/bash

SRCS_PATH			= $(CURDIR)

MLX_PATH			= minilibx-linux

MLX_FLAG			= -lmlx -lX11 -lXext

MLX_EX				= -L$(MLX_PATH) $(MLX_FLAG)

OBJS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})
OBJ_MAIN			= $(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.o})
#OBJS_BONUS			= $(addprefix p_bonus/, ${SRCS_BONUS:$(FILE_EXTENSION)=.o})
#OBJ_MAIN_BONUS		= $(addprefix p_bonus/, ${MAIN_BONUS:$(FILE_EXTENSION)=.o})

# Couleurs
RED 	= \\033[0;31m
GREEN 	= \\033[0;32m
YELLOW 	= \\033[0;33m
BLUE 	= \\033[0;34m
MAGENTA = \\033[0;35m
CYAN 	= \\033[0;36m
WHITE 	= \\033[0;37m
RESET 	= \\033[0m

all:		start $(NAME) end

start:
			@printf "%b" "$(BLUE)Compiling ...\n\033[m"

libft:
			@make -C libft > /dev/null
			
mlx:		
			@printf "%b" "$(BLUE)Compilating $(MLX_PATH)...\n\033[m"
			@make -sC $(MLX_PATH)
			@printf "%b" "$(BLUE)Compilation success\n\033[m"

$(NAME):	libft mlx ${OBJS} ${OBJ_MAIN}
			@($(CC) $(CFLAGS) ${OBJS} ${OBJ_MAIN} ${MLX_EX} -Llibft -lft)
			@mv a.out so_long

objs/%.o: 	$(SRCS_PATH)/%$(FILE_EXTENSION)
			@mkdir -p $(dir $@)
			@($(CC) $(CFLAGS) -c $< -o $@)
			
end:
			@printf "%b" "$(BLUE)Compilation success\n\033[m"
						
clean:
			@rm -rf objs libft/*.o
			@printf "%b" "$(RED)DELETE objs\n\033[m"
			
fclean:		clean
			@rm -rf ${NAME}
			@printf "%b" "$(RED)DELETE $(NAME)\n\033[m"
			
re:			fclean all

.PHONY:		all clean fclean re start end