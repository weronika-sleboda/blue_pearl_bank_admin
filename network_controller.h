#ifndef NETWORK_CONTROLLER_H
#define NETWORK_CONTROLLER_H

#include <string>

namespace blue_pearl_bank_admin
{

	class ServerManager;

	class NetworkController
	{

	public:

		~NetworkController();

	public:

		static NetworkController& network();
		bool runServer();
		void sendData(const std::string& message);
		void acquireData();
		const std::string const getClientData();

	private:

		NetworkController();
		NetworkController(NetworkController&) = delete;
		NetworkController(NetworkController&&) = delete;
		NetworkController& operator=(NetworkController&) = delete;
		NetworkController& operator=(NetworkController&&) = delete;

	private:

		ServerManager* serverManager;

	};

}

#endif