# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 14:59:16 by mpierce           #+#    #+#              #
#    Updated: 2025/01/14 13:59:45 by mpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

RANDNAME = map_gen

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

SOURCES = \
			srcs/arg_validation.c \
			srcs/cleanup.c \
			srcs/game_launch_utils.c \
			srcs/game_launch.c \
			srcs/hooks.c \
			srcs/image_load.c \
			srcs/open_map.c \
			srcs/path_check.c \
			srcs/screen_counter.c \
			srcs/so_long_utils.c \
			srcs/so_long.c \
			srcs/stdout_msgs.c

RANDSRCS = \
			map_generator/random_map.c \
			map_generator/random_map_utils.c \
			map_generator/random_map_extra.c \
			map_generator/random_map_help.c

RANDOBJS = $(RANDSRCS:.c=.o)

LIBMLX = ./MLX42

LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBFT_PATH = ./libftmaster

LIBFT = $(LIBFT_PATH)/libft.a

OBJECTS = $(SOURCES:.c=.o)

HEADERS	:= -I ./include -I $(LIBMLX)/include

GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \033[0m

all: .libmlx_cloned $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN) \nso_long Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

.libmlx_cloned:
	@git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX) && touch .libmlx_cloned
	@cmake $(LIBMLX) -B $(LIBMLX)/build && cmake --build $(LIBMLX)/build -j4

$(LIBFT):
	@make -C $(LIBFT_PATH) --no-print-directory

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@$(RM) $(OBJECTS) $(RANDOBJS)
	@make -C $(LIBFT_PATH) clean --no-print-directory
	@echo "$(GREEN)\nObjects Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

fclean: clean
	@make -C $(LIBFT_PATH) fclean --no-print-directory
	@$(RM) $(NAME)
	@echo "$(GREEN)\nExecutable Clean Complete\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"
	@$(RM) .libmlx_cloned
	@$(RM) ./MLX42
	@echo "$(GREEN)\nMLX42 Removed\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"
	@$(RM) $(RANDNAME)
	@echo "$(GREEN)\nMap Generator Removed\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

re: fclean all

good: all random clean

full: fclean all random
	@$(RM) $(OBJECTS) $(RANDOBJS)
	@echo "$(GREEN)\nObjects Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"
	@make -C $(LIBFT_PATH) clean --no-print-directory

random: $(RANDNAME)

$(RANDNAME): $(RANDOBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(RANDOBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(RANDNAME)
	@echo "$(GREEN) \nMap Generator Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

.PHONY: all clean fclean re libft full