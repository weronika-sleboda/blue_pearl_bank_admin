#include "log_in_process.h"
#include "network_controller.h"
#include "database.h"

namespace blue_pearl_bank_admin
{

	void LogInProcess::run
	(wxStaticText& messagePanel)
	{

		while (true)
		{

			NetworkController::network().acquireData();

			std::string login = 
				
				NetworkController::network().getClientData();

			if (logInValidation.validateLogIn(login))
			{

				NetworkController::network().sendData
				("LOG_IN_ACCEPTED");

				std::string user = logInValidation.getReceivedUserName();

				messagePanel.SetLabel(user + " has logged in.");

				std::string userInfo = logInValidation.getUserInfo();
				NetworkController::network().sendData(userInfo);

				break;

			}

			else
			{

				NetworkController::network().sendData
				("LOGIN_REJECTED");

				messagePanel.SetLabel("Failed attempt to log in.");
				break;

			}

		}

	}

}