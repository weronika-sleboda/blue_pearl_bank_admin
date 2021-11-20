#ifndef SERVER_MANAGER_H
#define SERVER_MANAGER_H

#include "server.h"
#include <string>

namespace blue_pearl_bank_admin
{

	class ServerManager : public Server
	{

	public:

		ServerManager();
	
	public:

		virtual const unsigned short const getPortNumber() override;
		bool listenToClient();
		bool acceptClient();
		bool sendData(const std::string& message);
		bool acquireData();
		const std::string const getClientData();

	private:

		boost::asio::ip::tcp::endpoint endpoint;
		boost::asio::ip::tcp::acceptor acceptor;
		std::string clientData;

	};

}

#endif