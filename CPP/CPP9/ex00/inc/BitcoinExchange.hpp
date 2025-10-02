#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <chrono>
#include <charconv>

typedef std::string str;

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define GREY "\033[0;90m"
#define RESET "\033[0m"

class btcEx
{
	private:
			std::map<std::chrono::year_month_day, float> value;

	public:
			btcEx();
			btcEx(const btcEx &copy);
			btcEx& operator=(const btcEx &copy);
			~btcEx();

			void loadFileToData(std::ifstream &file);
			bool isValidDate(const str &date);
			void readInput(std::ifstream &file);
			float findValue(const std::chrono::year_month_day &date, float &amount);

			class FileHeaderException : public std::exception
			{
				public:
						virtual const char *what() const noexcept override;
			};

			class FileErrorException : public std::exception
			{
				public:
						virtual const char *what() const noexcept override;
			};

			class DateExistException : public std::exception
			{
				public:
						virtual const char *what() const noexcept override;
			};
};