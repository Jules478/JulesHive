NAME = Accounts

CFLAGS = -Wall -Wextra -Werror 

STD = -std=c++98

SRCS = \
		tests.cpp \
		Account.cpp

HEADERS = \
		Account.hpp

GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \e[0m

TOTAL_FILES = $(words $(SRCS))
CURRENT_FILE = 0

all: $(NAME)

%.o: %.cpp $(HEADERS)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@c++ $(CFLAGS) $(STD) -c $< -o $@
	@printf "$(YELLOW)\r[%3d%%] Compiling %-20s$(RESET)" $$(( $(CURRENT_FILE) * 100 / $(TOTAL_FILES) )) $<

$(NAME): $(OBJS)
	@printf "\r%-50s\r" " "
	@c++ $(CFLAGS) $(STD) $(SRCS) -o $(NAME)
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