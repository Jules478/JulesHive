#include "sed.hpp"

static bool fileExists(const str& filename)
{
    std::ifstream testFile(filename);
    return testFile.good();
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Input error: <filename> <to be replaced> <replaced with>" << std::endl;
		return 1;
	}
	str line;
	str in = argv[1];
	str old = argv[2];
	str rep = argv[3];
	str out = in + ".replace";
	int len = old.length();
	if (old.empty())
	{
		std::cerr << "Input error: Cannot replace \"\"" << std::endl;
		return 1;
	}
	std::ifstream infile(in);
	if (!infile.is_open())
	{
		std::cerr << "File error: Cannot open " << in << std::endl;
		return 1;
	}
	if (fileExists(out))
	{
		char ans;
		std::cerr << "File " << out << " exists. Overwrite? [y/n]" << std::endl;
		while (1)
		{
			std::cin >> ans;
			switch (ans)
			{
				case 'y':
					[[fallthrough]];
				case 'Y':
					break;
				case 'n':
					[[fallthrough]];
				case 'N':
					std::cerr << "File not overwritten. Aborting..." << std::endl;
					infile.close();
					return 1;
				default:
					std::cerr << "Please confirm [y/n]" << std::endl;
					continue;
			}
			break;
		}
	}
	std::ofstream outfile(out);
	if (!outfile.is_open())
	{
		std::cerr << "File error: Cannot open " << out << std::endl;
		infile.close();
		return 1;
	}

	while (getline(infile, line))
	{
		line += "\n";
		size_t pos = 0;
		while ((pos = line.find(old, pos)) != str::npos)
		{
			line.erase(pos, len);
			line.insert(pos, rep);
			pos += rep.length();
		}
		outfile << line;
	}
	infile.close();
	outfile.close();
	return 0;
}