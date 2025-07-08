NAME = Brain

CFLAGS = -Wall -Wextra -Werror 

STD = -std=c++11

SRCS = \
		main.cpp 

OBJS = $(SRCS:.cpp=.o)

GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \e[0m

all: $(NAME)

%.o: %.cpp
	@c++ $(CFLAGS) $(STD) -c $< -o $@

$(NAME): $(OBJS)
	@c++ $(CFLAGS) $(STD) $(OBJS) -o $(NAME)
	@echo "$(GREEN) \n$(NAME) Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

clean:
	@rm -rf $(OBJS)
	@echo "$(GREEN)\nObject files cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)\n$(NAME) Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

re: fclean all

.PHONY: all clean fclean re