#pragma once

#include <iostream>
#include <algorithm>

typedef std::string str;

# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0m"

class	EmptyContainerException : public std::exception
{
	public:
			virtual const char	*what() const throw();
};

class	MemberNotFoundException : public std::exception
{
	public:
			virtual const char	*what() const throw();
};

const char	*EmptyContainerException::what() const throw()
{
	return ("Container is empty");
}

const char	*MemberNotFoundException::what() const throw()
{
	return ("Not found in container");
}

template <typename T> typename T::iterator easyfind(T& c, int i)
{
	if (c.begin() == c.end())
		throw EmptyContainerException();
	auto res = std::find(c.begin(), c.end(), i);
	if (res != c.end())
		return res;
	else
		throw MemberNotFoundException();
}
