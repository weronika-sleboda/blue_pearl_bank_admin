#include "network_controller.h"
#include "server_manager.h"

namespace blue_pearl_bank_admin
{

	NetworkController::NetworkController() :

		serverManager { nullptr }

	{}

	NetworkController::~NetworkController()
	{

		delete serverManager;

	}

	NetworkController& NetworkController::network()
	{

		static NetworkController controller;
		return controller;

	}

	bool NetworkController::runServer()
	{

		serverManager = new ServerManager{ };

		if (serverManager->listenToClient() && serverManager->acceptClient())
		{

			return true;

		}

		else
		{

			return false;

		}

	}

	void NetworkController::sendData(const std::string& message)
	{

		serverManager->sendData(message);

	}

	void NetworkController::acquireData()
	{

		serverManager->acquireData();

	}

	const std::string const NetworkController::getClientData()
	{

		return serverManager->getClientData();

	}
}