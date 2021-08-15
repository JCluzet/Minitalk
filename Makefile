# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 01:05:24 by jcluzet           #+#    #+#              #
#    Updated: 2021/07/20 00:02:46 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = client

NAME2 = server

OBJ_PATH = ./

SRC =				client.c \
					utils.c \

SRC_2 =				server.c \
					utils.c


OBJ_NAME = $(SRC:.c=.o)
OBJ2_NAME = $(SRC_2:.c=.o)

# Files

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ2 = $(addprefix $(OBJ_PATH), $(OBJ2_NAME))

# Flags

CC = gcc

CFLAGS =  -Wall -Werror -Wextra -g -fsanitize=address

# Rules

all:  $(NAME) $(NAME2)

$(NAME) :	$(OBJ)
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	gcc -o $(NAME) $(CFLAGS) $(SRC)
	@echo "\033[32m$(NAME) created\n\033[0m"

$(NAME2) :	$(OBJ2)
	@echo "\033[34mCreation of $(NAME2) ...\033[0m"
	gcc -o $(NAME2) $(CFLAGS) $(SRC_2)
	@echo "\033[32m$(NAME2) created\n\033[0m"

clean:
	@echo "\033[33mRemoval of .o files of $(NAME) & $(NAME2)...\033[0m"
	@rm -f $(OBJ) $(OBJ2)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean
	@echo "\033[33mRemoval of $(NAME) & $(NAME2)...\033[0m"
	@rm -f $(NAME) $(NAME2)
	@rm -rf server.dSYM client.dSYM >/dev/null
	@echo "\033[31mBinary $(NAME)  & $(NAME2) deleted\n\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
