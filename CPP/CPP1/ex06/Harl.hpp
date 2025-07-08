#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

typedef std::string str;

class Harl
{
	private:
			void debug(void);
			void info(void);
			void warning(void);
			void error(void);

	public:
			Harl();
			~Harl();
			void complain(str level);
};

#endif