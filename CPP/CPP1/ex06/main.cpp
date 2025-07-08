#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	if (argc > 2)
	{
		std::cout << "One complaint at a time please" << std::endl;
		return 1;
	}
	if (argc < 2)
	{
		std::cout << "Please complain about something" << std::endl;
		return 1;
	}
	str complaint = argv[1];
	harl.complain(complaint);
	return 0;
}