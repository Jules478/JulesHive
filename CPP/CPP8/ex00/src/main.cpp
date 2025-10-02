#include "../inc/easyfind.hpp"
#include <vector>
#include <array>

int main()
{
	try
	{
		std::cout << PURPLE << "/////" << RESET << " Test 1 " << PURPLE << "/////" << RESET << std::endl;
		std::vector<int> vec;
		auto it = easyfind(vec, 5);
		std::cout << "Member " << *it << " found" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << PURPLE << "/////" << RESET << " Test 2 " << PURPLE << "/////" << RESET << std::endl;
		std::vector<int> vec = {1, 2, 3, 4};
		auto it = easyfind(vec, 5);
		std::cout << "Member " << *it << " found" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << PURPLE << "/////" << RESET << " Test 3 " << PURPLE << "/////" << RESET << std::endl;
		std::array<int,5> array = {2, 1, 5, 3, 4};
		auto it = easyfind(array, 3);
		std::cout << "Member " << *it << " found" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << PURPLE << "/////" << RESET << " Test 4 " << PURPLE << "/////" << RESET << std::endl;
		std::array<int,7> array = {8, 4, 9, 3, 1, 9, 6};
		auto it = easyfind(array, 9);
		std::cout << "Member " << *it << " found" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
		
	return 0;
}