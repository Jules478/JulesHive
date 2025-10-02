#include "../inc/PmergeMe.hpp"

///// Orthodox Canonical Form /////

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	(void)copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	(void)copy;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

///// Real Business Starts Here /////

PmergeMe::PmergeMe(int argc, char **argv)
{
	if (argc == 1)
	{
		throw "missing argument";
	}
	int num;
	std::vector<int> vec;
	std::deque<int> deque;
	for (int i = 1; i < argc; i++)
	{
		std::stringstream input(argv[i]);
		if (!(input >> num) || !(input.eof()))
			throw "input error";
		if (num < 0)
			throw "negative value";
		vec.push_back(num);
		deque.push_back(num);
	}
	std::cout << CYAN "\nBefore: " RESET;
	printVector(vec, 1);
	auto start = std::chrono::system_clock::now();
	runVec(vec);
	auto end = std::chrono::system_clock::now();
	std::cout << "Time to process a range of " GREEN << argc - 1 << RESET " elements with std::vector: " CYAN << end - start << RESET << std::endl;

	std::cout << CYAN "\nBefore: " RESET;
	printDeque(deque, 1);
	start = std::chrono::system_clock::now();
	runDeque(deque);
	end = std::chrono::system_clock::now();
	std::cout << "Time to process a range of " GREEN << argc - 1 << RESET " elements with std::deque: " CYAN << end - start << RESET << std::endl;
}

///////////// Vector Functions Start Here /////////////

void PmergeMe::runVec(std::vector<int>& vec)
{
	pairAndSortElements(vec, 1);
	vec = _mainV;
	std::cout << PURPLE "After: " RESET;
	printVector(vec, 1);
}

void PmergeMe::pairAndSortElements(std::vector<int>& vec, size_t scale)
{
	if (scale > vec.size() / 2) 
		return;
	for (size_t i = 0; i + (scale * 2) <= vec.size(); i += (scale * 2))
	{
		int leftMax = vec[i + scale - 1];
		int rightMax = vec[i + scale + scale - 1];
		
		if (leftMax > rightMax)
		{
			for (size_t j = 0; j < scale; j++)
				std::swap(vec[i + j], vec[i + scale + j]);
		}
	}
	pairAndSortElements(vec, scale * 2);
	initializationInsertion(vec, scale);
}

void PmergeMe::initializationInsertion(std::vector<int>& vec, size_t scale)
{
	_mainV.clear();
	_pendV.clear();
	for (size_t i = 0; i < scale * 2; i++) // add first two elements to main
		_mainV.push_back(vec[i]);
	for (size_t i = scale * 2; i + (scale * 2) <= vec.size(); i += scale * 2)
	{
		for (size_t j = 0; j < scale; j++)
			_pendV.push_back(vec[i + j]);
		for (size_t j = 0; j < scale; j++)
			_mainV.push_back(vec[i + scale + j]);
	}
	size_t nextIndex = scale * 2;
	for (size_t i = scale * 2; i + (scale * 2) <= vec.size(); i += scale * 2)
	{
		nextIndex = i + (scale * 2);
	}
	if (nextIndex + scale <= vec.size()) // add any remaining elements that aren't paired
	{
		for (size_t j = 0; j < scale; j++)
			_pendV.push_back(vec[nextIndex + j]);
		nextIndex += scale;
	}
	performJacobsthal(vec, scale);
	if (nextIndex < vec.size()) // add incomplete elements to the end
	{
		for (size_t j = nextIndex; j < vec.size(); j++)
			_mainV.push_back(vec[j]);
	}
	vec = _mainV;
}

void PmergeMe::performJacobsthal(std::vector<int>& vec, size_t scale)
{
	(void)vec;
	if (_pendV.empty())
		return;
	int groupNo = _pendV.size() / scale;
	if (groupNo == 0)
		return;
	std::vector<int> jacobsthal = generateJacobsthal(groupNo); // generate sequence
	std::vector<std::vector<int>> pendGroups;
	for (int i = 0; i < groupNo; i++) // sort pend for indexing later
	{
		std::vector<int> group;
		for (size_t j = 0; j < scale; j++)
		{
			group.push_back(_pendV[i * scale + j]);
		}
		pendGroups.push_back(group);
	}
	std::vector<bool> inserted(groupNo, false); // for tracking if element has been inserted
	for (size_t j = 0; j < jacobsthal.size() && j < (size_t)groupNo; j++)
	{
		int groupIndex = jacobsthal[j];
		if (groupIndex >= 0 && groupIndex < groupNo && !inserted[groupIndex])
		{
			inserted[groupIndex] = true;
			std::vector<int>& group = pendGroups[groupIndex];
			if (scale == 1) // use binary search for final insert
			{
				int element = group[0];
				size_t left = 0;
				size_t right = _mainV.size();
				while (left < right)
				{
					size_t mid = left + (right - left) / 2;
					if (_mainV[mid] < element)
						left = mid + 1;
					else
						right = mid;
				}
				_mainV.insert(_mainV.begin() + left, element);
			}
			else
			{
				int groupMax = group[scale - 1]; // binary search for element insert
				size_t left = 0;
				size_t right = _mainV.size() / scale;
				while (left < right)
				{
					size_t mid = left + (right - left) / 2;
					size_t midGroupStart = mid * scale;
					if (midGroupStart + scale - 1 < _mainV.size() && 
						_mainV[midGroupStart + scale - 1] < groupMax)
						left = mid + 1;
					else
						right = mid;
				}
				size_t insertIndex = left * scale;
				for (size_t i = 0; i < scale; i++)
					_mainV.insert(_mainV.begin() + insertIndex + i, group[i]);
			}
		}
	}
	for (int i = 0; i < groupNo; i++) // insert remaining elements
	{
		if (!inserted[i])
		{
			std::vector<int>& group = pendGroups[i];
			if (scale == 1)
			{
				int element = group[0];
				size_t left = 0;
				size_t right = _mainV.size();
				while (left < right)
				{
					size_t mid = left + (right - left) / 2;
					
					if (_mainV[mid] < element)
						left = mid + 1;
					else
						right = mid;
				}
				_mainV.insert(_mainV.begin() + left, element);
			}
			else
			{
				for (size_t j = 0; j < scale; j++)
					_mainV.push_back(group[j]);
			}
		}
	}
	_pendV.clear();
}

///////////// Vector Functions End Here /////////////

std::vector<int> PmergeMe::generateJacobsthal(int maxGroups)
{
	std::vector<int> jacobsthal;
	if (maxGroups <= 0)
		return jacobsthal;
	std::vector<bool> used(maxGroups, false);
	std::vector<int> sequence = {1, 1};
	while (sequence.back() < maxGroups)
	{
		size_t next = sequence[sequence.size()-1] + 2 * sequence[sequence.size()-2];
		sequence.push_back(next);
	}
	for (size_t i = 1; i < sequence.size(); i++) // add indexes to add based on Jacobsthal sequence
	{
		int start = std::min(sequence[i], maxGroups);
		int end = (i > 1) ? sequence[i-1] : 0;
		for (int j = start; j > end; j--)
		{
			int index = j - 1;
			if (index >= 0 && index < maxGroups && !used[index])
			{
				jacobsthal.push_back(index);
				used[index] = true;
			}
		}
	}
	return jacobsthal;
}

///////////// Deque Functions Start Here /////////////

void PmergeMe::runDeque(std::deque<int>& deque)
{
	pairAndSortElements(deque, 1);
	deque = _mainD;
	std::cout << PURPLE "After: " RESET;
	printDeque(deque, 1);
}

void PmergeMe::pairAndSortElements(std::deque<int>& deque, size_t scale)
{
	if (scale > deque.size() / 2) 
		return;
	for (size_t i = 0; i + (scale * 2) <= deque.size(); i += (scale * 2))
	{
		int leftMax = deque[i + scale - 1];
		int rightMax = deque[i + scale + scale - 1];
		
		if (leftMax > rightMax)
		{
			for (size_t j = 0; j < scale; j++)
				std::swap(deque[i + j], deque[i + scale + j]);
		}
	}
	pairAndSortElements(deque, scale * 2);
	initializationInsertion(deque, scale);
}

void PmergeMe::initializationInsertion(std::deque<int>& deque, size_t scale)
{
	_mainD.clear();
	_pendD.clear();
	for (size_t i = 0; i < scale * 2; i++) // add first two elements to main
		_mainD.push_back(deque[i]);
	for (size_t i = scale * 2; i + (scale * 2) <= deque.size(); i += scale * 2)
	{
		for (size_t j = 0; j < scale; j++)
			_pendD.push_back(deque[i + j]);
		for (size_t j = 0; j < scale; j++)
			_mainD.push_back(deque[i + scale + j]);
	}
	size_t nextIndex = scale * 2;
	for (size_t i = scale * 2; i + (scale * 2) <= deque.size(); i += scale * 2)
	{
		nextIndex = i + (scale * 2);
	}
	if (nextIndex + scale <= deque.size()) // add any remaining elements that aren't paired
	{
		for (size_t j = 0; j < scale; j++)
			_pendD.push_back(deque[nextIndex + j]);
		nextIndex += scale;
	}
	performJacobsthal(deque, scale);
	if (nextIndex < deque.size()) // add incomplete elements to the end
	{
		for (size_t j = nextIndex; j < deque.size(); j++)
			_mainD.push_back(deque[j]);
	}
	deque = _mainD;
}

void PmergeMe::performJacobsthal(std::deque<int>& deque, size_t scale)
{
	(void)deque;
	if (_pendD.empty())
		return;
	int groupNo = _pendD.size() / scale;
	if (groupNo == 0)
		return;
	std::vector<int> jacobsthal = generateJacobsthal(groupNo); // generate sequence
	std::deque<std::deque<int>> pendGroups;
	for (int i = 0; i < groupNo; i++) // sort pend for indexing later
	{
		std::deque<int> group;
		for (size_t j = 0; j < scale; j++)
		{
			group.push_back(_pendD[i * scale + j]);
		}
		pendGroups.push_back(group);
	}
	std::vector<bool> inserted(groupNo, false); // for tracking if element has been inserted
	for (size_t j = 0; j < jacobsthal.size() && j < (size_t)groupNo; j++)
	{
		int groupIndex = jacobsthal[j];
		if (groupIndex >= 0 && groupIndex < groupNo && !inserted[groupIndex])
		{
			inserted[groupIndex] = true;
			std::deque<int>& group = pendGroups[groupIndex];
			if (scale == 1) // use binary search for final insert
			{
				int element = group[0];
				size_t left = 0;
				size_t right = _mainD.size();
				while (left < right)
				{
					size_t mid = left + (right - left) / 2;
					if (_mainD[mid] < element)
						left = mid + 1;
					else
						right = mid;
				}
				_mainD.insert(_mainD.begin() + left, element);
			}
			else
			{
				int groupMax = group[scale - 1]; // binary search for element insert
				size_t left = 0;
				size_t right = _mainD.size() / scale;
				while (left < right)
				{
					size_t mid = left + (right - left) / 2;
					size_t midGroupStart = mid * scale;
					if (midGroupStart + scale - 1 < _mainD.size() && 
						_mainD[midGroupStart + scale - 1] < groupMax)
						left = mid + 1;
					else
						right = mid;
				}
				size_t insertIndex = left * scale;
				for (size_t i = 0; i < scale; i++)
					_mainD.insert(_mainD.begin() + insertIndex + i, group[i]);
			}
		}
	}
	for (int i = 0; i < groupNo; i++) // insert remaining elements
	{
		if (!inserted[i])
		{
			std::deque<int>& group = pendGroups[i];
			if (scale == 1)
			{
				int element = group[0];
				size_t left = 0;
				size_t right = _mainD.size();
				while (left < right)
				{
					size_t mid = left + (right - left) / 2;
					
					if (_mainD[mid] < element)
						left = mid + 1;
					else
						right = mid;
				}
				_mainD.insert(_mainD.begin() + left, element);
			}
			else
			{
				for (size_t j = 0; j < scale; j++)
					_mainD.push_back(group[j]);
			}
		}
	}
	_pendD.clear();
}

///////////// Deque Functions End Here /////////////
