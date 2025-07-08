#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstring>
# include <iomanip>

typedef std::string str;

class	Contact
{
	private:
			str forename;
			str surname;
			str nickname;
			str phone;
			str secret;

	public:
			Contact();
			~Contact();

			void	setFore(str fore);
			void	setSur(str sur);
			void	setNick(str nick);
			void	setPhone(str phone);
			void	setSecret(str secret);

			str	getFore() const;
			str	getSur() const;
			str	getNick() const;
			str	getPhone() const;
			str	getSecret() const;
};

#endif