NAME = Julesed

CFLAGS = -Wall -Wextra -Werror 

STD = -std=c++11

GFLAG = -g

SRCS = \
		main.cpp 

HEADERS = \
		sed.hpp	

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
	@rm -rf *.replace
	@echo "$(GREEN)\n$(NAME) Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

debug: $(DEBUG_OBJS)
	@c++ $(CFLAGS) $(GFLAG) $(STD) $(DEBUG_OBJS) -o $(NAME)
	@echo "$(GREEN) \n$(NAME) Compiled with Debug Flags\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

re: fclean all

.PHONY: all clean fclean debug re