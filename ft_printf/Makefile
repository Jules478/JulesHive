# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 14:17:05 by mpierce           #+#    #+#              #
#    Updated: 2024/11/22 14:43:54 by mpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

RM = rm -rf

SOURCES = ft_printf.c printf_hex.c printf_ptr.c printf_types.c printf_uint.c

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $(NAME)
	$(AR) -r $@ $?

$(LIBFT): 
	make -C $(LIBFT_PATH) all

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean: 
	make -C $(LIBFT_PATH) clean
	$(RM) -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft