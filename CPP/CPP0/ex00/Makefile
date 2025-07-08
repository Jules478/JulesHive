NAME = megaphone

CFLAGS = -Wall -Wextra -Werror 

STD = -std=c++11

SRCS = \
		megaphone.cpp

GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \e[0m

all: $(NAME)

$(NAME):	$(SRCS)
	@c++ $(CFLAGS) $(STD) $(SRCS) -o $(NAME)
	@echo "$(GREEN) \n$(NAME) Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

clean:
	@rm -rf $(NAME)
	@echo "$(GREEN)\n$(NAME) Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

.PHONY: all clean