#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

namespace blue_pearl_bank_admin
{

	class Account
	{

	public:

		Account
		(

			std::string theFirstName,
			std::string theLastName,
			std::string theEmailAddress,
			std::string thePassword
		
		);

		const std::string getFirstName();
		const std::string getLastName();
		const std::string getEmailAddress();
		const std::string getPassword();
		const std::string getFunds();

		bool depositFunds(long long amount);
		bool withdrawawFunds(long long amount);

	private:

		std::string firstName;
		std::string lastName;
		std::string emailAddress;
		std::string password;
		long long funds;

	};

}

#endif