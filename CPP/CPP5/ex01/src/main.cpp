#include "../inc/Bureaucrat.hpp"

int main()
{
	{
		// tests

		std::cout << PURPLE << "-----" << RESET << " Tests " << PURPLE << "-----" << RESET << std::endl;
		Bureaucrat harvey("Harvey", 1);
		Bureaucrat rachel("Rachel", 20);
		Bureaucrat louis("Louis", 150);

		Form one("Big Form", 1, 1);
		Form onefiddy("Little Form", 150, 1);
		Form one_copy(one);
		Form two("Medium Form", 20, 1);
		std::cout << std::endl;

		std::cout << YELLOW << "---" << RESET << " Grade to sign (1) " << YELLOW << "---" << RESET << std::endl;
		harvey.signForm(one);
		rachel.signForm(one);
		louis.signForm(one_copy);
		std::cout << std::endl;
		std::cout << YELLOW << "---" << RESET << " Grade to sign (20) " << YELLOW << "---" << RESET << std::endl;
		harvey.signForm(two);
		rachel.signForm(two);
		louis.signForm(two);
		std::cout << std::endl;
		std::cout << YELLOW << "---" << RESET << " Grade to sign (150) " << YELLOW << "---" << RESET << std::endl;
		harvey.signForm(onefiddy);
		rachel.signForm(onefiddy);
		louis.signForm(onefiddy);
	}
	return 0;
}