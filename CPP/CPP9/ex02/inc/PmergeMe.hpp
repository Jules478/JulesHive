#pragma once

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <sstream>
#include <cstddef>
#include <chrono>

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

class PmergeMe
{
	private:
			std::vector<int> _mainV;
			std::vector<int> _pendV;

			std::deque<int> _mainD;
			std::deque<int> _pendD;

	public:
			PmergeMe();
			PmergeMe(int argc, char **argv);
			PmergeMe(const PmergeMe& copy);
			PmergeMe& operator=(const PmergeMe& copy);
			~PmergeMe();

			// Vector Functions
			void runVec(std::vector<int>& vec);
			void pairAndSortElements(std::vector<int>& vec, size_t scale);
			void initializationInsertion(std::vector<int>& vec, size_t scale);
			void performJacobsthal(std::vector<int>& vec, size_t scale);

			// Deque Functions
			void runDeque(std::deque<int>& deque);
			void pairAndSortElements(std::deque<int>& deque, size_t scale);
			void initializationInsertion(std::deque<int>& deque, size_t scale);
			void performJacobsthal(std::deque<int>& deque, size_t scale);

			std::vector<int> generateJacobsthal(int maxGroups);
};

void printVector(std::vector<int> vec, size_t scale);
void printDeque(std::deque<int> deque, size_t scale);