#include "../inc/Span.hpp"

int main()
{
	{
		std::cout << PURPLE << "/////" << RESET << " Subject Test " << PURPLE << "/////" << RESET << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << PURPLE << "/////" << RESET << " Own Tests " << PURPLE << "/////" << RESET << std::endl;
		Span sp = Span(10);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try 
		{
			std::vector<int> moreNumbers = {1, 2, 4, 8};
			sp.addRange(moreNumbers.begin(), moreNumbers.end());
			std::cout << "Range added successfully" << std::endl;
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::vector<int> evenMoreNumbers = {15, 19, 22};
			sp.addRange(evenMoreNumbers.begin(), evenMoreNumbers.end());
			std::cout << "Range added successfully" << std::endl;
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			sp.addNumber(15);
			std::cout << "Number added successfully" << std::endl;
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			sp.addNumber(22);
			std::cout << "Number added successfully" << std::endl;
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
		Span empty = Span(5);
		try
		{
			std::cout << empty.shortestSpan() << std::endl;
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << empty.longestSpan() << std::endl;
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
		empty.addNumber(1);
		try
		{
			std::cout << empty.shortestSpan() << std::endl;
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << empty.longestSpan() << std::endl;
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
		Span big = Span(100000);
		std::srand(time(NULL));
		for (int i = 0; i < 100000; i++)
		{
			
			int random_int = rand() % 1000000000;
			big.addNumber(random_int);
		}
		try
		{
			std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
			std::cout << "Longest span: " << big.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}