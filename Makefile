# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 13:20:08 by atoof             #+#    #+#              #
#    Updated: 2023/03/22 13:02:09 by atoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
RESET = \033[0m

NAME = pipex
SRC = error_print.c child.c free.c main.c helper_functions_1.c helper_functions_2.c
OBJ = $(SRC:.c=.o)
HEADER = pipex.h
LIBFT = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Building $(NAME)...$(RESET)"
	make -C ./libft
	cc $(FLAGS) $(OBJ) $(LIBFT) -o $@
	@echo "$(GREEN)Finished building $(NAME)$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	cc $(FLAGS) -c $< -o $@
	@echo "$(GREEN)Finished compiling $<$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning up object files...$(RESET)"
	make clean -C ./libft
	/bin/rm -f $(OBJ)
	@echo "$(GREEN)Finished cleaning up object files$(RESET)"

fclean: clean
	@echo "$(YELLOW)Cleaning up $(NAME)...$(RESET)"
	make fclean -C ./libft
	/bin/rm -f $(NAME)
	@echo "$(GREEN)Finished cleaning up $(NAME)$(RESET)"

re: fclean all
