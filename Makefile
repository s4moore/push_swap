# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2023/12/08 16:38:45 by samoore           #+#    #+#             #
#   Updated: 2023/12/19 16:17:08 by samoore          ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

CC = gcc
NAME = push_swap

SRC_FILES = push_swap_get_nums.c push_swap_rules_rr.c push_swap_utils_3.c push_swap.c \
			push_swap_merge_sort.c push_swap_rules_sp.c push_swap_utils_4.c \
			push_swap_pre_sort.c push_swap_utils.c push_swap_cost.c push_swap_rules_r.c push_swap_utils_2.c

OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))

BONUS_FILES = checker.c  checker_get_nums.c checker_merge_sort.c checker_rules_rr.c checker_utils.c \
			  checker_instructions.c checker_rules_r.c checker_rules_sp.c

CC_FLAGS = 

SRC_DIR = srcs/
BONUS_DIR = bonus/
OBJ_DIR = objs/
INCLUDE_DIR = includes/

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_FILES)
	$(CC) $(CC_FLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re