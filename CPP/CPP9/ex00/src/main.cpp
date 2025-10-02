#include "../inc/BitcoinExchange.hpp"

static bool fileExists(const str& filename)
{
	std::ifstream testFile(filename);
	return testFile.good();
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "./btc <.csv> <input>" << std::endl;
		return -1;
	}
	btcEx bitcoin;
	if (!fileExists(argv[1]))
	{
		std::cout << RED "File error: " RESET << argv[1] << " does not exist" << std::endl;
		return -1;
	}
	if (!fileExists(argv[2]))
	{
		std::cout << RED "File error: " RESET << argv[2] << " does not exist" << std::endl;
		return -1;
	}
	std::ifstream csv(argv[1]);
	if (!csv.is_open())
	{
		std:: cout << RED "File error: " RESET << argv[1] << " cannot open" << std::endl;
		return -1;
	}
	std::ifstream input(argv[2]);
	if (!input.is_open())
	{
		std:: cout << RED "File error: " RESET << argv[2] << " cannot open" << std::endl;
		return -1;
	}
	try { bitcoin.loadFileToData(csv); }
	catch (const std::exception &e)
	{
		std::cout << RED "File error: " RESET "csv " << e.what() << std::endl;
		return -1;
	}
	try { bitcoin.readInput(input); }
	catch (const std::exception &e)
	{
		std::cout << RED "Error: " RESET << e.what() << std::endl;
		return -1;
	}
	return 0;
}