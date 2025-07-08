#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "Harl complains about \"DEBUG\"" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "Harl complains about \"INFO\"" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl << "Harl complains about \"WARNING\"" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "Harl complains about \"ERROR\"" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "Harl complains about \"NOTHING\"" << std::endl;
	harl.complain("NOTHING");

	return 0;
}