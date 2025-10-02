#include "../inc/RPN.hpp"

void run_tests()
{
	std::cout << PURPLE "\n-----" RESET " Reverse Polish Notation " PURPLE "-----\n" RESET << std::endl;
	std::cout << PURPLE "\n---" RESET " Subject Tests " PURPLE "---\n" RESET << std::endl;
	{
		str sum = "8 9 * 9 - 9 - 9 - 4 - 1 +";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "42\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "7 7 * 7 -";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "42\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum =  "1 2 * 2 / 2 * 2 4 - +";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "0\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "(1 + 1)";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "Error\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << PURPLE "\n---" RESET " Basic Operations " PURPLE "---\n" RESET << std::endl;
	{
		str sum = "3 4 +";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "7\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "9 3 -";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "6\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "5 6 *";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "30\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "9 3 /";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "3\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << PURPLE "\n---" RESET " Multiple Operations " PURPLE "---\n" RESET << std::endl;
	{
		str sum = "2 3 + 4 *";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "20\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "2 3 4 + *";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "14\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "1 2 + 3 4 + *";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "21\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "8 2 / 3 +";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "7\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << PURPLE "\n---" RESET " Chain Operations " PURPLE "---\n" RESET << std::endl;
	{
		str sum = "1 2 3 + +";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "6\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "2 3 4 * +";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "14\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "9 3 / 2 -";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "1\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "1 1 1 1 + + +";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "4\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << PURPLE "\n---" RESET " Invalid Calculations " PURPLE "---\n" RESET << std::endl;
	{
		str sum = "";
		std::cout << YELLOW "Sum: " RESET << "\"" << sum << "\"" << CYAN "\nExpected: " RESET "Error\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "       ";
		std::cout << YELLOW "Sum: " RESET << "\"" << sum << "\"" << CYAN "\nExpected: " RESET "Error\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "seven four add";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "Error\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "7 4 + 0 /";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "Error\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "5 + 5";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "Error\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "6 2";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "Error\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "4 6 ?";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "Error\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "1 1 1 1 1 1 + + + + + + + + + + +";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "Error\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
	{
		str sum = "2 2 + + 2 + + 2 2 2 2";
		std::cout << YELLOW "Sum: " RESET << sum << CYAN "\nExpected: " RESET "Error\n" GREEN "Actual:   " RESET;
		try
		{
			RPN rpn(sum);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
}

str get_input()
{
	str input;

	input = "";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cin.clear();
		exit(0);
	}
	if (input.empty())
		return "";
	return input;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Run tests? (y/N) ";
		str input = get_input();
		while (input != "y" && input != "Y" && input != "n" && input != "N")
		{
			std::cout << "Invalid input: (y/N)" << std::endl;
			input = get_input();
		}
		if (input == "y" || input == "Y")
		{
			run_tests();
		}
	}
	else if (argc == 2)
	{
		try
		{
			RPN rpn(argv[1]);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
	}
	else
	{
		str input;
		for (int i = 1; i < argc; i++)
		{
			input += argv[i];
			input += " ";
		}
		try
		{
			RPN rpn(input);
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
		}
	}
	return 0;
}