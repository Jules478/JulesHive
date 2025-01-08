# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 15:43:52 by mpierce           #+#    #+#              #
#    Updated: 2024/12/23 14:30:44 by mpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BNAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

SOURCES = \
		sources/cleanup.c \
		sources/duplicate_check.c \
		sources/index_utils.c \
		sources/push_swap.c \
		sources/push.c \
		sources/revrotate.c \
		sources/rotate.c \
		sources/run_sort.c \
		sources/solver_utils_ab.c \
		sources/solver_utils_ba.c \
		sources/solver.c \
		sources/sorter_main.c \
		sources/sorting.c \
		sources/stack_create.c \
		sources/swap.c \
		sources/validation.c 

BSOURCES = \
		sources/cleanup.c \
		sources/duplicate_check.c \
		sources/push.c \
		sources/revrotate.c \
		sources/rotate.c \
		sources/stack_create.c \
		sources/swap.c \
		sources/validation.c \
		bonus_sources/checker_utils.c \
		bonus_sources/checker.c

LIBFT_PATH = ./libftmaster

LIBFT = $(LIBFT_PATH)/libft.a

GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \033[0m

all: $(NAME)

$(NAME): $(SOURCES) $(LIBFT)
	@$(CC) $(CFLAGS) $(SOURCES) $(LIBFT) -o $(NAME)
	@echo "$(GREEN) \npush_swap Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_PATH) --no-print-directory

clean:
	@make -C $(LIBFT_PATH) clean --no-print-directory

fclean: clean
	@make -C $(LIBFT_PATH) fclean --no-print-directory
	@$(RM) $(NAME)
	@$(RM) $(BNAME)
	@echo "$(GREEN)\nExecutable Clean Complete\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

re: fclean all

bonus: $(BNAME)

$(BNAME): $(BSOURCES) $(LIBFT)
	@$(CC) $(CFLAGS) $(BSOURCES) $(LIBFT) -o $(BNAME)
	@echo "$(GREEN)\nBonus Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

full: fclean all bonus
	@make -C $(LIBFT_PATH) clean --no-print-directory

100: $(NAME)
	@MAX=0; \
	for i in $(shell seq 1 500); do \
		ARGS=$$(shuf -i 1-2147483647 -n 100 | tr '\n' ' '); \
		RESULT=$$(./$(NAME) $$ARGS | wc -l); \
		if [ $$RESULT -gt $$MAX ]; then \
			MAX=$$RESULT; \
		fi; \
		COMPLETION=$$(($$i * 100 / 500)); \
		printf "\r%% Progress: $$COMPLETION%%"; \
		sleep 0.01; \
	done; \
	echo "$(PURPLE)\nTarget Operations: 700\nWorst Case Operations: $$MAX$(RESET)"
	
500: $(NAME)
	@MAX=0; \
	for i in $(shell seq 1 100); do \
		ARGS=$$(shuf -i 1-2147483647 -n 500 | tr '\n' ' '); \
		RESULT=$$(./$(NAME) $$ARGS | wc -l); \
		if [ $$RESULT -gt $$MAX ]; then \
			MAX=$$RESULT; \
		fi; \
		COMPLETION=$$(($$i)); \
		printf "\r%% Progress: $$COMPLETION%%"; \
		sleep 0.01; \
	done; \
	echo "$(PURPLE)\nTarget Operations: 5500\nWorst Case Operations: $$MAX$(RESET)"

100check: $(NAME)
	@for i in $(shell seq 1 10); do \
		ARGS=$$(shuf -i 1-2147483647 -n 100 | tr '\n' ' '); \
		./$(NAME) $$ARGS | ./checker_linux $$ARGS; \
	done

500check: $(NAME)
	@for i in $(shell seq 1 10); do \
		ARGS=$$(shuf -i 1-2147483647 -n 500 | tr '\n' ' '); \
		./$(NAME) $$ARGS | ./checker_linux $$ARGS; \
	done

100bonus: $(NAME) $(BNAME)
	@for i in $(shell seq 1 10); do \
		ARGS=$$(shuf -i 1-2147483647 -n 100 | tr '\n' ' '); \
		./$(NAME) $$ARGS | ./checker $$ARGS; \
	done

500bonus: $(NAME) $(BNAME)
	@for i in $(shell seq 1 10); do \
		ARGS=$$(shuf -i 1-2147483647 -n 500 | tr '\n' ' '); \
		./$(NAME) $$ARGS | ./checker $$ARGS; \
	done

.PHONY: all clean fclean re libft full 100 500 100check 500check bonus 100bonus 500bonus
