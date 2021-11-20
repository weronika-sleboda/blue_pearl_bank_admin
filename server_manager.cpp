#include "server_manager.h"

using namespace boost;

namespace blue_pearl_bank_admin
{

	ServerManager::ServerManager() :

		endpoint { asio::ip::address_v4::any(), getPortNumber() },
		acceptor { ioService, endpoint },
		clientData { "" }

	{}

	const unsigned short const ServerManager::getPortNumber()
	{

		return Server::getPortNumber();

	}

	bool ServerManager::listenToClient()
	{

		try
		{

			acceptor.listen();

			return true;

		}
		
		catch (system::system_error error)
		{

			return false;

		}

	}

	bool ServerManager::acceptClient()
	{

		try
		{

			acceptor.accept(socket);

			return true;

		}

		catch (system::system_error error)
		{

			return false;

		}

	}

	bool ServerManager::sendData(const std::string& message)
	{

		try
		{

			asio::write(socket, asio::buffer(message + '\n'));

			return true;

		}

		catch (system::system_error error)
		{

			return false;

		}

	}

	bool ServerManager::acquireData()
	{

		try
		{

			asio::streambuf buffer;
			asio::read_until(socket, buffer, "\n");
			clientData = asio::buffer_cast<const char*>(buffer.data());

			return true;

		}
		
		catch (system::system_error error)
		{

			return false;

		}

	}

	const std::string const ServerManager::getClientData()
	{

		return clientData;

	}

}