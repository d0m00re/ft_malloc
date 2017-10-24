# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 15:38:04 by alhelson          #+#    #+#              #
#    Updated: 2017/10/14 19:07:44 by alhelson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Wall -Wextra -Werror
INC= includes
SRC_PATH= srcs
NAME= libft_malloc.so

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

LIB = ./libft_malloc_$(HOSTTYPE).so

SRC_M_MEMORY_MANAGE_PATH=m_memory_manage

OBJ_PATH=srcs

############################################
## SOURCES
############################################
SRC_M_MEMORY_MANAGE=  alloc_mem.c free_mem.c memory_create_block.c\
			memory_manage_make.c memory_found_type.c\
			alloc_area_zone.c init_int_tab.c memory_mothership_manage.c\
			free_area_zone.c memory_free.c memory_search_block.c\
			realloc_area_zone.c show_alloc_mem.c display_nbr.c\
			show_memory_spec.c show_memory_tab_status.c\
			calcul_nb_octet.c

############################################
## OBJECT
############################################
OBJ_M_MEMORY_MANAGE= $(patsubst %.c, %.o, $(SRC_M_MEMORY_MANAGE))
OBJ_M_MM=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_MEMORY_MANAGE))

############################################
## FORMAT_PATH
############################################
SRC_M_MM = $(addprefix ./$(SRC_M_MEMORY_MANAGE_PATH)/, $(SRC_M_MEMORY_MANAGE))

############################################
## RULES
############################################
.PHONY: all lib clean $(NAME)

all: $(NAME)

$(NAME): $(OBJ_M_MM)
	@echo "[$(NAME)]"
	$(CC) -shared -o $(LIB) $(OBJ_M_MM) -I ./$(INC)
	ln -fs $(LIB) $@

$(OBJ_M_MM): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_MEMORY_MANAGE_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@echo "COMPIL [MANAGE MEMORY]"

clean:
	@rm -f $(OBJ_M_MM)
	@echo "[CLEAN]"

fclean: clean
	@rm -f $(NAME)
	@echo "DELETE [$(NAME)]"

re: fclean all
