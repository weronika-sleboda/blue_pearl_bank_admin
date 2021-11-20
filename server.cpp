#include "server.h"

namespace blue_pearl_bank_admin
{

	Server::Server() :

		portNumber { 3333 },
		socket { ioService }

	{}

	const unsigned short const Server::getPortNumber()
	{

		return portNumber;

	}

}