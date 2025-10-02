#pragma once

#include <iostream>
#include <stack>
#include <charconv>

typedef std::string str;

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define GREY "\033[0;90m"
#define RESET "\033[0m"

enum e_operator
{
	INVALID,
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION
};

class RPN
{
	private:
			std::stack<int> _stack;
			e_operator _operator;
	
	public:
			RPN();
			RPN(str arg);
			RPN(const RPN& copy);
			RPN& operator=(const RPN& copy);
			~RPN();

			bool isValidOperator(int c);
};

