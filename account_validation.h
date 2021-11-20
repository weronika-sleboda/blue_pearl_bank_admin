#ifndef ACCOUNT_VALIDATION_H
#define ACCOUNT_VALIDATION_H

#include <string>

namespace blue_pearl_bank_admin
{

	class AccountValidation
	{

	public:

		AccountValidation(std::string theUserInfo);

	public:

		bool emailAddressAlreadyExists();
		bool validAccount();
		bool validFirstName();
		bool validLastName();
		bool validEmailAddress();
		bool validPassword();

		std::string getFirstName();
		std::string getLastName();
		std::string getEmailAddress();
		std::string getPassword();

	private:

		void splitUserInfo();

	private:

		std::string userInfo;
		std::string firstName;
		std::string lastName;
		std::string emailAddress;
		std::string password;

	};

}

#endif