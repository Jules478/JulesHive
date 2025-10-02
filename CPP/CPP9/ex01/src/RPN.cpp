#include "../inc/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& copy)
{
	this->_stack = copy._stack;
}

RPN& RPN::operator=(const RPN& copy)
{
	if (this != &copy)
	{
		this->_stack = copy._stack;
	}
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isValidOperator(int c)
{
	switch (c)
	{
		case '*':
			_operator = MULTIPLICATION;
			return true;
		case '/':
			_operator = DIVISION;
			return true;
		case '-':
			_operator = SUBTRACTION;
			return true;
		case '+':
			_operator = ADDITION;
			return true;
		default:
			_operator = INVALID;
	}
	return false;
	// if (c == '*' && c == '/' && c == '-' && c == '+')
	// 	return true;
	// return false;
}

RPN::RPN(str arg)
{
	for (int i = 0; arg[i]; i++)
	{
		if (arg[i] == ' ')
			continue;
		if (isdigit(arg[i]))
			_stack.push(arg[i] - 48);
		else if (_stack.size() >= 2 && isValidOperator(arg[i]))
		{
			int second = _stack.top();
			_stack.pop();
			int first = _stack.top();
			_stack.pop();
			switch (_operator)
			{
				case MULTIPLICATION:
					_stack.push(first * second);
					break;
				case DIVISION:
					if (second == 0)
						throw "Error: division by zero";
					_stack.push(first / second);
					break;
				case SUBTRACTION:
					_stack.push(first - second);
					break;
				case ADDITION:
					_stack.push(first + second);
					break;
				default:
					throw "Error: unknown input";
			}
		}	
		else if (_stack.size() == 1 && isValidOperator(arg[i]))
			throw "Error: syntax error";
		else
			throw "Error: bad input";
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else if (_stack.size() > 1)
		throw "Error: operands missing operator";
	else
		throw "Error: empty expression";
}
