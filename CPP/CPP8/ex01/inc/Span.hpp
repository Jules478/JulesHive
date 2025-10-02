#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

typedef std::string str;

# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0m"

class Span
{
	private:
			unsigned int _max;
			std::vector<int> _c;

	public:
			Span() = delete;
			Span(unsigned int N);
			Span(const Span& copy);
			Span& operator=(const Span& copy);
			~Span();

			void addNumber(int n);
			int shortestSpan();
			int longestSpan();
			void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};