# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:06:11 by mrocher           #+#    #+#              #
#    Updated: 2023/12/06 10:42:24 by mrocher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC 		= gcc
CFLAGS	= -Wall -Werror -Wextra
AUTHOR	= mrocher
HASH	= 

NOVISU 	= 0

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

FILE_EXTENSION	= .c

SRCS			= pipex_utils.c
SRCS_BONUS		= pipex_utils_bonus.c

MAIN			= pipex.c
MAIN_BONUS		= pipex_bonus.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

SHELL 				:= /bin/bash

SRCS_PATH			= $(CURDIR)

OBJS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})
OBJ_MAIN			= $(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.o})
OBJS_BONUS			= $(addprefix p_bonus/, ${SRCS_BONUS:$(FILE_EXTENSION)=.o})
OBJ_MAIN_BONUS		= $(addprefix p_bonus/, ${MAIN_BONUS:$(FILE_EXTENSION)=.o})

################################################################################
#                                 Makefile logic                               #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

COM_STRING   = "compiling"

ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Darwin) 
	RUN_CMD = script -q $@.log $1 > /dev/null; \
				RESULT=$$?
else ifeq ($(detected_OS),Linux)
	RUN_CMD = script -q -c "$(1)" $@.log > /dev/null; \
				RESULT=$$?; \
				sed -i '1d' $@.log; \
				sed -i "$$(($$(wc -l < $@.log)-1)),\$$d" $@.log
else
	RUN_CMD = $(1) 2> $@.log; \
				RESULT=$$?
endif

ifeq ($(shell git rev-parse HEAD &>/dev/null; echo $$?),0)
	AUTHOR	:= $(shell git log --format='%aN' | sort -u | awk '{printf "%s, ", $$0}' | rev | cut -c 3- | rev)
	HASH	:= $(shell git rev-parse --short HEAD)
endif

define run_and_test
printf "%b%-46b" "$(COM_COLOR)$(COM_STRING) " "$(OBJ_COLOR)$(@F)$(NO_COLOR)"; \
$(RUN_CMD); \
if [ $$RESULT -ne 0 ]; then \
	printf "%b\n" "$(ERROR_COLOR)[✖]$(NO_COLOR)"; \
	rm -rf .files_changed; \
	if [ $(NOVISU) -eq 0 ]; then \
		echo; \
	fi; \
elif [ -s $@.log ]; then \
	printf "%b\n" "$(WARN_COLOR)[⚠]$(NO_COLOR)"; \
else  \
	printf "%b\n" "$(OK_COLOR)[✓]$(NO_COLOR)"; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

define save_files_changed
	FILE_CPP=`echo $(SRCS) $(MAIN)`; \
	FILE_OBJ=`find objs -type f -name '*.o' 2>/dev/null | sed 's/objs\///'`; \
	TO_COMPILE=`echo $$FILE_CPP | wc -w`; \
	for FILE in $$FILE_CPP; do \
		for OBJ in $$FILE_OBJ; do \
			if [ $${FILE%$(FILE_EXTENSION)} = $${OBJ%.o} ]; then \
				if [ $(SRCS_PATH)/$$FILE -ot objs/$$OBJ ]; then \
					FILE_DEP=objs/$$OBJ; \
					HEAD_FILES=`< $$FILE_DEP xargs -0 | grep -oh "\w*.h\w*"`; \
					RECOMPILE=0; \
					for HEAD in $$HEAD_FILES; do \
						if [ $(SRCS_PATH)/$$HEAD -nt objs/$$OBJ ]; then \
							RECOMPILE=1; \
							break; \
						fi; \
					done; \
					if [ $$RECOMPILE -eq 0 ]; then \
						((TO_COMPILE=$$TO_COMPILE-1)); \
					fi;\
				fi; \
			fi; \
		done; \
	done; \
	echo 0/$$TO_COMPILE > .files_changed
endef

################################################################################
#                                 Makefile rules                             #
################################################################################

all: header setup $(NAME)
	@rm -rf .files_changed
	
header:
	@printf "%b" "$(OK_COLOR)"
	@echo "                                _                   "
	@echo "                               | |                  "
	@echo " _ __ ___   _ __    ___    ___ | |__    ___  _ __   "
	@echo " |  _   _ \ |  __| / _ \  / __||  _ \  / _ \|  __|  "
	@echo " | | | | | || |   | (_) || (__ | | | ||  __/| |     "
	@echo " |_| |_| |_||_|    \___/  \___||_| |_| \___||_|     "
	@echo
ifneq ($(HASH),)
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(CFLAGS)\n\033[m"
	@echo

libft:		header
			@make -C libft > /dev/null
			@printf "%-53b%b" "$(COM_COLOR)libft:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
			
setup:
			@$(call save_files_changed)

$(NAME):	${OBJS} ${OBJ_MAIN} libft
			@$(call run_and_test,$(CC) $(CFLAGS) -o $@ ${OBJS} ${OBJ_MAIN} -Llibft -lft)

objs/%.o: 	$(SRCS_PATH)/%$(FILE_EXTENSION)
			@mkdir -p $(dir $@)
			@$(call run_and_test,$(CC) $(CFLAGS) -c $< -o $@)

bonus:		${OBJS_BONUS} ${OBJ_MAIN_BONUS} libft
			@$(call run_and_test,$(CC) $(CFLAGS) -o $@ ${OBJS_BONUS} ${OBJ_MAIN_BONUS} -Llibft -lft)
			@mv bonus pipex_bonus

p_bonus/%.o: $(SRCS_PATH)/%$(FILE_EXTENSION)
			@mkdir -p $(dir $@)
			@$(call run_and_test,$(CC) $(CFLAGS) -c $< -o $@)

clean:		header
			@rm -rf objs p_bonus .files_changed
			@printf "%-53b%b" "$(COM_COLOR)clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
			
fclean:		header clean
			@rm -rf $(NAME) pipex_bonus .files_changed
			@printf "%-53b%b" "$(COM_COLOR)fclean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
			
re:			fclean all

.PHONY:		all clean fclean libft re header bonus