#include "../inc/PmergeMe.hpp"

void printVector(std::vector<int> vec, size_t scale)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ((i + 1) % scale == 0 ? (i == vec.size() - 1 ? "\n" : ", ") : (i == vec.size() - 1 ? "\n" : " "));
	std::cout << std::endl;
}

void printDeque(std::deque<int> deque, size_t scale)
{
	for (size_t i = 0; i < deque.size(); i++)
		std::cout << deque[i] << ((i + 1) % scale == 0 ? (i == deque.size() - 1 ? "\n" : ", ") : (i == deque.size() - 1 ? "\n" : " "));
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	try
	{
		PmergeMe thing(argc, argv);
	}
	catch (const char* e)
	{
		std::cout << "Error: " << e << std::endl;
	}
	return 0;
}

// ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`