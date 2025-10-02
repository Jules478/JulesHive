#include "../inc/Span.hpp"

Span::Span(unsigned int N) : _max(N)
{
}

Span::Span(const Span& copy) : _max(copy._max)
{
	this->_c = copy._c;
}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		this->_max = copy._max;
		this->_c = copy._c;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (this->_c.size() == this->_max)
		throw std::out_of_range("Error: Container full");
	this->_c.push_back(n);
}

int Span::shortestSpan()
{
	int store;
	if (_c.size() == 1 || _c.empty())
		throw std::out_of_range("Error: Container too small");
	std::vector<int> temp = _c;
	std::sort(temp.begin(), temp.end());
	int shortest = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < temp.size() - 1; i++)
	{
			store = temp[i + 1] - temp[i];
			if (store < shortest)
				shortest = store;
	}
	return shortest;
}

int Span::longestSpan()
{
	if (_c.size() == 1 || _c.empty())
		throw std::out_of_range("Error: Container too small");
	std::vector<int> temp = _c;
	std::sort(temp.begin(), temp.end());
	int longest = temp[temp.size() - 1] - temp[0];
	return longest;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_c.size() + std::distance(begin, end) > _max)
		throw std::out_of_range("Error: Container would exceed max limit");
	_c.insert(_c.end(), begin, end);
}
