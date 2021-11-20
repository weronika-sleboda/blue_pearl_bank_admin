#include "log_in_validation.h"
#include "database.h"
#include "network_controller.h"

namespace blue_pearl_bank_admin
{

	LogInValidation::LogInValidation() :

		receivedEmail { "" },
		userName { "" },
		userInfo { "" }

	{}

	std::string LogInValidation::getReceivedEmail()
	{

		return receivedEmail;

	}

	std::string LogInValidation::getReceivedUserName()
	{

		return userName;

	}

	bool LogInValidation::validateLogIn(std::string login)
	{

		userName = "";
		receivedEmail = "";

		for (int index = 0; index < login.length(); index++)
		{

			if (login[index] == '\n')
			{

				break;

			}

			receivedEmail += login[index];

		}

		Database::retriveLogIn(receivedEmail);

		if (Database::getCovetedInfo() == login)
		{

			retriveUserName(receivedEmail);

			Database::retriveAccount(receivedEmail);
			userInfo = Database::getCovetedInfo();

			return true;

		}

		return false;

	}

	void LogInValidation::retriveUserName(std::string givenEmail)
	{

		Database::retriveFirstName(givenEmail);
		std::string firstName = Database::getCovetedInfo();
		firstName.pop_back();

		Database::retriveLastName(givenEmail);
		std::string lastName = Database::getCovetedInfo();
		lastName.pop_back();

		userName = firstName + " " + lastName;

	}

	const std::string LogInValidation::getUserInfo()
	{

		std::string firstName {"First Name: "};
		std::string lastName { "Last Name: " };
		std::string email{ "Email: " };
		std::string funds { "Funds: " };;

		int splitIndex { 0 };

		for (int index = 0; index < userInfo.length(); index++)
		{

			if (userInfo[index] == '\n')
			{

				splitIndex = index + 1;
				break;

			}

			firstName += userInfo[index];

		}

		for (int index = splitIndex; index < userInfo.length(); index++)
		{

			if (userInfo[index] == '\n')
			{

				splitIndex = index + 1;
				break;

			}

			lastName += userInfo[index];

		}

		for (int index = splitIndex; index < userInfo.length(); index++)
		{

			if (userInfo[index] == '\n')
			{

				splitIndex = index + 1;
				break;

			}

			email += userInfo[index];

		}

		for (int index = splitIndex; index < userInfo.length(); index++)
		{

			if (userInfo[index] == '\n')
			{

				splitIndex = index + 1;
				break;

			}

			funds += userInfo[index];

		}

		return firstName + "\n" + lastName + "\n" + email + "\n" + funds;

	}


}