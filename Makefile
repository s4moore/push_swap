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
BONUS_NAME = checker
CC_FLAGS = -Wall -Werror -Wextra -g

SRC_FILES = cost.c  cost_optimise.c  find_nums.c  get_nums.c  lis.c \
			memory.c  merge_sort.c  push_swap.c  rules_r.c  rules_rr.c \
			rules_sp.c  sort_first.c  sort_main.c  up_down.c  utils.c

BONUS_FILES = checker.c  checker_get_nums.c checker_merge_sort.c \
			  checker_rules_rr.c checker_utils.c checker_memory.c \
			  checker_instructions.c checker_rules_r.c checker_rules_sp.c

OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))
BONUS_OBJ_FILES = $(patsubst %.c, $(BONUS_OBJ_DIR)%.o, $(BONUS_FILES))

SRC_DIR = srcs/
BONUS_DIR = bonus/
OBJ_DIR = objs/
BONUS_OBJ_DIR = objs/bonus/
INCLUDE_DIR = includes/
INCLUDE_FILE = push_swap.h
BONUS_INCLUDE_FILE = checker.h

m: man
man: mandatory
mandatory: $(NAME)

b: bonus
bonus: $(BONUS_NAME)

all: $(NAME) $(BONUS_NAME)


$(NAME): $(OBJ_DIR) $(OBJ_FILES) $(INCLUDE_DIR)$(INCLUDE_FILE)
	@$(CC) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CC_FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


$(BONUS_NAME): $(BONUS_OBJ_DIR) $(BONUS_OBJ_FILES) $(INCLUDE_DIR)$(BONUS_INCLUDE_FILE)
	@$(CC) $(BONUS_OBJ_FILES) -o $(BONUS_NAME)

$(BONUS_OBJ_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(CC_FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re m man mandatory b bonus