#ifndef LOG_IN_VALIDATION_H
#define LOG_IN_VALIDATION_H

#include <string>

namespace blue_pearl_bank_admin
{

	class LogInValidation
	{

	public:

		LogInValidation();

	public:

		bool validateLogIn(std::string login);
		std::string getReceivedEmail();
		std::string getReceivedUserName();
		const std::string getUserInfo();

	private:

		void retriveUserName(std::string givenEmail);

	private:

		std::string receivedEmail;
		std::string userName;
		std::string userInfo;

	};

}

#endif