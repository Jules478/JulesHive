#pragma once

#include <iostream>

typedef std::string str;

# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0m"

template <typename T1, typename T2> void iter(T1 *arr, int len, T2(*f))
{
	if (!arr)
		return ;
	for (int i = 0; i < len; i++)
		f(arr[i]);
}
