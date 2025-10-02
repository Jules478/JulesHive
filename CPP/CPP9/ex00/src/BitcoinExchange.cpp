#include "../inc/BitcoinExchange.hpp"

btcEx::btcEx()
{
}

btcEx::btcEx(const btcEx &copy)
{
	value = copy.value;
}

btcEx& btcEx::operator=(const btcEx &copy)
{
	if (this != &copy)
		value = copy.value;
	return *this;
}

btcEx::~btcEx()
{
}

void btcEx::loadFileToData(std::ifstream &file)
{
	str line;
	str date;
	size_t pos;
	float rate;

	getline(file, line);
	if (line != "date,exchange_rate")
		throw FileHeaderException();
	while (getline(file, line))
	{
		pos = line.find(',');
		if (pos == str::npos)
			throw FileErrorException();
		date = line.substr(0, pos);
		str rateStr = line.substr(pos + 1);
		auto [ptr, ec] = std::from_chars(rateStr.data(), rateStr.data() + rateStr.size(), rate);
		if (ec != std::errc{})
			throw FileErrorException();
		if (ptr != rateStr.data() + rateStr.size())
			throw FileErrorException();
		if (!isValidDate(date) || rate < 0)
			throw FileErrorException();
		std::chrono::year_month_day ymd { std::chrono::year{std::stoi(date.substr(0, 4))}, std::chrono::month{static_cast<unsigned int>(std::stoi(date.substr(5, 2)))}, std::chrono::day{static_cast<unsigned int>(std::stoi(date.substr(8, 2)))} };
		value.insert({ ymd, rate });
	}
}

bool btcEx::isValidDate(const str& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	try
	{
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		std::chrono::year_month_day ymd { std::chrono::year{year}, std::chrono::month{static_cast<unsigned int>(month)}, std::chrono::day{static_cast<unsigned int>(day)} };
		return ymd.ok();
	}
	catch (const std::exception&)
	{
		return false;
	}
}

void btcEx::readInput(std::ifstream &file)
{
	str line;
	str date;
	size_t pos;
	str amountStr;
	float amount;
	float worth;

	getline(file, line);
	if (line != "date | value")
		throw FileHeaderException();
	while (getline(file, line))
	{
		pos = line.find('|');
		if (pos == str::npos)
		{
			std::cout << RED "Error: " RESET "bad input" << std::endl;
			continue;
		}
		date = line.substr(0, pos);
		amountStr = line.substr(pos + 1);
		bool hasSpacesBefore = (date.back() == ' ');
		bool hasSpacesAfter = (amountStr.front() == ' ');
		if (!hasSpacesBefore || !hasSpacesAfter)
		{
			std::cout << RED "Error: " RESET "bad input" << std::endl;
			continue;
		}
		date.erase(date.find_last_not_of(" ") + 1);
		amountStr.erase(0, amountStr.find_first_not_of(" "));
		auto [ptr, ec] = std::from_chars(amountStr.data(), amountStr.data() + amountStr.size(), amount);
		if (ec != std::errc{} || ptr != amountStr.data() + amountStr.size())
		{
			std::cout << RED "Error: " RESET "bad input" << std::endl;
			continue;
		}
		if (!isValidDate(date))
		{
			std::cout << RED "Error: " RESET "invalid date" << std::endl;
			continue;
		}
		if (amount < 0)
		{
			std::cout << RED "Error: " RESET "amount cannot be negative" << std::endl;
			continue;
		}
		if (amount > 2147483647.0f)
		{
			std::cout << RED "Error: " RESET "amount too large" << std::endl;
			continue;
		}
		std::chrono::year_month_day ymd { std::chrono::year{std::stoi(date.substr(0, 4))}, std::chrono::month{static_cast<unsigned int>(std::stoi(date.substr(5, 2)))}, std::chrono::day{static_cast<unsigned int>(std::stoi(date.substr(8, 2)))} };
		try
		{
			worth = findValue(ymd, amount);
			std::cout << static_cast<int>(ymd.year()) << "-" << static_cast<unsigned int>(ymd.month()) << "-" << static_cast<unsigned int>(ymd.day())<< " => " << amount << " | " << worth << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << RED "Error: " RESET << e.what() << std::endl;
		}
	}
}

float btcEx::findValue(const std::chrono::year_month_day &date, float &amount)
{
	auto it = value.upper_bound(date);
	if (it == value.begin())
		throw DateExistException();
	--it;
	return it->second * amount;
}

const char* btcEx::FileHeaderException::what() const noexcept
{
	return "header error";
}

const char* btcEx::FileErrorException::what() const noexcept
{
	return "data format error";
}

const char* btcEx::DateExistException::what() const noexcept
{
	return "date not found";
}
