#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <limits>

typedef std::string str;

# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
			MutantStack();
			MutantStack(const MutantStack& copy);
			MutantStack<T>& operator=(const MutantStack& copy);
			~MutantStack();

			typedef typename std::stack<T>::container_type::iterator iterator;
			typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
			typedef typename std::stack<T>::container_type::const_iterator const_iterator;
			typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

			iterator begin();
			iterator end();
			reverse_iterator rbegin();
			reverse_iterator rend();

			const_iterator begin() const;
			const_iterator end() const;
			const_reverse_iterator rbegin() const;
			const_reverse_iterator rend() const;
};