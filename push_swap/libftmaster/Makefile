# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:11:53 by mpierce           #+#    #+#              #
#    Updated: 2024/12/12 17:55:56 by mpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
	  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew_bonus.c \
	  ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c \
	  ft_lstlast_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	  ft_lstmap_bonus.c get_next_line_bonus.c ft_printf.c printf_hex.c printf_ptr.c \
	  printf_types.c printf_uint.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -r $@ $? > /dev/null 2>&1
	@echo "$(GREEN) \nLIBFT Compilation Complete\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

%.o: %.c
	@cc -c $(CFLAGS) $?

clean:
	@rm -f $(OBJECTS)
	@echo "$(GREEN) \nLIBFT Object Clean Complete\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN) \nLIBFT File Clean Complete\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

re: fclean all

.PHONY: all clean fclean re
