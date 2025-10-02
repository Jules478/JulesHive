NAME = Intern

CFLAGS = -Wall -Wextra -Werror 

GFLAG = -g

STD = -std=c++17

INC_DIR = ./inc

SRC_DIR = ./src

OBJ_DIR = ./obj

SRCS = \
		$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/Bureaucrat.cpp \
		$(SRC_DIR)/AForm.cpp \
		$(SRC_DIR)/ShrubberyCreationForm.cpp \
		$(SRC_DIR)/RobotomyRequestForm.cpp \
		$(SRC_DIR)/PresidentialPardonForm.cpp \
		$(SRC_DIR)/Intern.cpp

HEADERS = \
			$(INC_DIR)/Bureaucrat.hpp \
			$(INC_DIR)/AForm.hpp \
			$(INC_DIR)/ShrubberyCreationForm.hpp \
			$(INC_DIR)/RobotomyRequestForm.hpp \
			$(INC_DIR)/PresidentialPardonForm.hpp \
			$(INC_DIR)/Intern.hpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEBUG_OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.debug.o)

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

GREEN = \e[1;32m
PURPLE = \e[1;35m
YELLOW = \e[1;33m
RESET = \e[0m

TOTAL_FILES = $(words $(SRCS))
CURRENT_FILE = 0

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@c++ $(CFLAGS) $(STD) -c $< -o $@
	@printf "$(YELLOW)\r[%3d%%] Compiling %-30s$(RESET)" $$(( $(CURRENT_FILE) * 100 / $(TOTAL_FILES) )) $<

$(OBJ_DIR)/%.debug.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@c++ $(CFLAGS) $(GFLAG) $(STD) -c $< -o $@

shadow: CFLAGS := -Wall -Wextra -Werror -Wshadow
shadow: re

$(NAME): $(OBJS)
	@printf "\r%-50s\r" " "
	@c++ $(CFLAGS) $(STD) $(OBJS) -o $(NAME)
	@echo "$(GREEN) \n$(NAME) Compiled\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)\nObject files cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

fclean: clean
	@rm -rf $(NAME) *_shrubbery
	@echo "$(GREEN)\n$(NAME) Cleaned\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

debug: $(DEBUG_OBJS)
	@c++ $(CFLAGS) $(GFLAG) $(STD) $(DEBUG_OBJS) -o $(NAME)
	@echo "$(GREEN) \n$(NAME) Compiled with Debug Flags\n$(RESET)"
	@echo "$(PURPLE)------------------------------------$(RESET)"

re: fclean all

.PHONY: all clean fclean debug shadow re