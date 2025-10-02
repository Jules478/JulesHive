#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(str target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		this->setSigned(copy.getSigned());
		this->_target = copy._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::performAction() const
{
	std::ofstream outfile(_target + "_shrubbery");
	outfile << "    oxoxoo    ooxoo" << std::endl;
	outfile << "  ooxoxo oo  oxoxooo" << std::endl;
	outfile << " oooo xxoxoo ooo ooox" << std::endl;
	outfile << " oxo o oxoxo  xoxxoxo" << std::endl;
	outfile << "  oxo xooxoooo o ooo" << std::endl;
	outfile << "    ooo\\oo\\  /o/o" << std::endl;
	outfile << "        \\  \\/ /" << std::endl;
	outfile << "         |   /" << std::endl;
	outfile << "         |  |" << std::endl;
	outfile << "         | D|" << std::endl;
	outfile << "         |  |" << std::endl;
	outfile << "         |  |" << std::endl;
	outfile << "  ______/____\\____" << std::endl;
}
