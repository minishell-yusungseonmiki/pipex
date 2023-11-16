# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 19:03:47 by seonmiki          #+#    #+#              #
#    Updated: 2023/11/15 19:12:26 by seonmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -Imandatory/include
LIBFT = -L./libft -lft

NAME = pipex
SRC_DIR = $(PROJECT_DIR)/source
OBJ_DIR = $(PROJECT_DIR)/object
SRCS = $(shell find $(SRC_DIR) -name *.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

ifdef BONUS
	PROJECT_DIR = bonus
else
	PROJECT_DIR = mandatory
endif

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft all
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	$(MAKE) -C ./libft fclean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make all

bonus :
	$(MAKE) all BONUS=1

.PHONY: all clean fclean re bonus