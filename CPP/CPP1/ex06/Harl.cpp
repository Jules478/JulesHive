#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
	std::cout << "I love having no errors in my code. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe removing one line in my code breaks it. You didn’t tell me it would! If you did, I wouldn’t be removing lines!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have a better language. I’ve been coding in C for years whereas you started coding last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to bocal now." << std::endl;
}

void Harl::complain(str level)
{
	str levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			switch (i)
			{
				case 0:
					Harl::debug();
				case 1:
					Harl::info();
				case 2:
					Harl::warning();
				case 3:
					Harl::error();
				return;
				
			}
		}
	}
	std::cout << "I don't have anything to complain about." << std::endl;
}