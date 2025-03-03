# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 17:26:54 by mpierce           #+#    #+#              #
#    Updated: 2025/03/03 16:56:11 by mpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread 

RM = rm -rf

SRCS = \
		srcs/init.c \
		srcs/philo_utils.c \
		srcs/philo.c \
		srcs/threads_utils.c \
		srcs/threads.c

OBJS = $(SRCS:.c=.o)


GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(MOBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MOBJS) -o $(NAME)
	@echo "$(GREEN) \nPhilosophers Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@$(RM) $(OBJS) $(MOBJS) $(BOBJS)
	@echo "$(GREEN)\nOBJS Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)\nExecutable Clean Complete\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

re: fclean all

full: fclean all
	@$(RM) $(OBJS) $(MOBJS) $(BOBJS)
	@echo "$(GREEN)\nOBJS Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

.PHONY: all clean fclean re full 