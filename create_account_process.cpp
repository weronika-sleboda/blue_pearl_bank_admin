#include "create_account_process.h"
#include "network_controller.h"
#include "account_validation.h"
#include "account.h"
#include "database.h"

namespace blue_pearl_bank_admin
{

	void CreateAccountProcess::run
	(wxStaticText& messagePanel)
	{

		while (true)
		{

			std::string userData = getUserData();

			AccountValidation validation{ userData };

			if (validation.validAccount())
			{

				createAccount(messagePanel, validation);

				NetworkController::network().sendData
				("ACCOUNT_ACCEPTED");

				break;

			}

			else
			{

				messagePanel.SetLabel
				("Failed attempt to login.");

				std::string error = getError(messagePanel, validation);

				NetworkController::network().sendData(error);

				break;

			}
		}

	}

	const std::string CreateAccountProcess::getUserData()
	{

		NetworkController::network().acquireData();

		std::string userData =

			NetworkController::network().getClientData();

		return userData;

	}

	void CreateAccountProcess::createAccount
	(wxStaticText& messagePanel, AccountValidation& validation)
	{

		Account account
		{
			validation.getFirstName(),
			validation.getLastName(),
			validation.getEmailAddress(),
			validation.getPassword()

		};

		Database::addAccount(account);

		std::string userEmail = account.getEmailAddress();

		Database::retriveFirstName(userEmail);

		std::string firstName = Database::getCovetedInfo();
		firstName.pop_back();

		Database::retriveLastName(userEmail);


		messagePanel.SetLabel
		(

			firstName +
			" has created an account."

		);

	}

	const std::string CreateAccountProcess::getError
	(wxStaticText& messagePanel, AccountValidation& validation)
	{

		std::string error;

		int errorCounter { 0 };

		if (!validation.validFirstName())
		{

			error =

				"First name should be shorter than 30 letters"
				" and shouldn't be blank.\n";

			errorCounter++;

		}

		if (!validation.validLastName())
		{

			error +=

				"Last name should be shorter than 30 letters"
				" and shouldn't be blank.\n";

			errorCounter++;

		}

		if (!validation.validEmailAddress())
		{

			error +=

				"Email address is incorrect. ";

			errorCounter++;

		}

		if (!validation.validPassword())
		{

			error +=

				"Password should be longer than 6.";

			errorCounter++;

		}

		if (errorCounter == 4)
		{

			error = "You didn't fill the application!";

		}

		return error;

	}

}