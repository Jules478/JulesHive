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
	void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	str levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "I don't have anything to complain about." << std::endl;
}