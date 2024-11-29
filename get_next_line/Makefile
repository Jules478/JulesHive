# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:11:53 by mpierce           #+#    #+#              #
#    Updated: 2024/11/29 12:46:18 by mpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mandatory

BNAME = bonus

SOURCES = \
	  get_next_line.c get_next_line_utils.c main.c

BSOURCES = \
	   get_next_line_bonus.c get_next_line_utils_bonus.c main.c

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

GREEN = \e[1;32m
RESET = \033[0m

SIZE1 = -D BUFFER_SIZE=1

SIZE2 = -D BUFFER_SIZE=42

SIZE3 = -D BUFFER_SIZE=10000000

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $?
	@echo "$(GREEN) Compilation without BUFFER_SIZE Successful\n$(RESET)"

small: $(OBJECTS)
	$(CC) $(CFLAGS) $(SIZE1) -o $(NAME) $(OBJECTS)
	@echo "$(GREEN) Compilation with BUFFER_SIZE=1 Successful\n$(RESET)"

mid: $(OBJECTS)
	$(CC) $(CFLAGS) $(SIZE2) -o $(NAME) $(OBJECTS)
	@echo "$(GREEN) Compilation with BUFFER_SIZE=42 Successful\n$(RESET)"
	
big: $(OBJECTS)
	$(CC) $(CFLAGS) $(SIZE3) -o $(NAME) $(OBJECTS)
	@echo "$(GREEN) Compilation with BUFFER_SIZE=10000000 Successful\n$(RESET)"
	
bonus: $(BOBJECTS)
	$(CC) $(CFLAGS) -o $@ $?
	@echo "$(GREEN) Bonus Compilation Without BUFFER_SIZE Successful\n$(RESET)"

bonussmall: $(BOBJECTS)
	$(CC) $(CFLAGS) $(SIZE1) -o $(BNAME) $(BOBJECTS)
	@echo "$(GREEN) Bonus Compilation with BUFFER_SIZE=1 Successful\n$(RESET)"

bonusmid: $(BOBJECTS)
	$(CC) $(CFLAGS) $(SIZE2) -o $(BNAME) $(BOBJECTS)
	@echo "$(GREEN) Bonus Compilation with BUFFER_SIZE=42 Successful\n$(RESET)"

bonusbig: $(BOBJECTS)
	$(CC) $(CFLAGS) $(SIZE3) -o $(BNAME) $(BOBJECTS)
	@echo "$(GREEN) Bonus Compilation with BUFFER_SIZE=10000000 Successful\n$(RESET)"

both: 	$(NAME) $(BNAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus both small mid big bonussmall bonusmid bonusbig
