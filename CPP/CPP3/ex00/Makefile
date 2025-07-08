NAME = ClapTrap

CFLAGS = -Wall -Wextra -Werror 

GFLAG = -g

STD = -std=c++11

SRCS = \
		main.cpp \
		ClapTrap.cpp

HEADERS = \
		ClapTrap.hpp

OBJS = $(SRCS:.cpp=.o)
DEBUG_OBJS = $(SRCS:.cpp=.debug.o)

GREEN = \e[1;32m
PURPLE = \e[1;35m
YELLOW = \e[1;33m
RESET = \e[0m

TOTAL_FILES = $(words $(SRCS))
CURRENT_FILE = 0

all: $(NAME)

%.o: %.cpp $(HEADERS)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@c++ $(CFLAGS) $(STD) -c $< -o $@
	@printf "$(YELLOW)\r[%3d%%] Compiling %-20s$(RESET)" $$(( $(CURRENT_FILE) * 100 / $(TOTAL_FILES) )) $<

%.debug.o: %.cpp $(HEADERS)
	@c++ $(CFLAGS) $(GFLAG) $(STD) -c $< -o $@

shadow: CLAGS := -Wall -Wextra -Werror -Wshadow
shadow: re

$(NAME): $(OBJS)
	@printf "\r%-50s\r" " "
	@c++ $(CFLAGS) $(STD) $(OBJS) -o $(NAME)
	@echo "$(GREEN) \n$(NAME) Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

clean:
	@rm -rf $(OBJS) $(DEBUG_OBJS)
	@echo "$(GREEN)\nObject files cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)\n$(NAME) Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

debug: $(DEBUG_OBJS)
	@c++ $(CFLAGS) $(GFLAG) $(STD) $(DEBUG_OBJS) -o $(NAME)
	@echo "$(GREEN) \n$(NAME) Compiled with Debug Flags\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

re: fclean all

.PHONY: all clean fclean debug shadow re