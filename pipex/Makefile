# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 11:48:41 by mpierce           #+#    #+#              #
#    Updated: 2025/02/18 16:23:15 by mpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

CSRCS = \
			srcs/pipex_utils.c \
			srcs/piping_utils.c \
			srcs/handle_files.c

MSRCS = \
			srcs/pipex.c \
			srcs/piping.c

BSRCS = \
			bonus/pipex_bonus.c \
			bonus/handle_heredoc.c \
			bonus/piping_bonus.c

LIBFT_PATH = ./libftmaster

LIBFT = $(LIBFT_PATH)/libft.a

COBJS = $(CSRCS:.c=.o)

MOBJS = $(MSRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \033[0m

all: $(NAME)

$(NAME): $(COBJS) $(MOBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(COBJS) $(MOBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN) \npipex Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_PATH) --no-print-directory

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@$(RM) $(COBJS) $(MOBJS) $(BOBJS)
	@make -C $(LIBFT_PATH) clean --no-print-directory
	@echo "$(GREEN)\nOBJS Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

fclean: clean
	@make -C $(LIBFT_PATH) fclean --no-print-directory
	@$(RM) $(NAME)
	@echo "$(GREEN)\nExecutable Clean Complete\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

re: fclean all

bonus: $(COBJS) $(BOBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(COBJS) $(BOBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN) \npipex Bonus Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"
	@$(RM) $(COBJS) $(MOBJS) $(BOBJS)
	@make -C $(LIBFT_PATH) clean --no-print-directory

full: fclean all
	@$(RM) $(COBJS) $(MOBJS) $(BOBJS)
	@echo "$(GREEN)\nOBJS Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"
	@make -C $(LIBFT_PATH) clean --no-print-directory

good: all clean

.PHONY: all clean fclean re libft full good bonus