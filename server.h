#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>

namespace blue_pearl_bank_admin
{

	class Server
	{

	public:

		virtual ~Server() = default;

	protected:

		Server();

	protected:

		virtual const unsigned short const getPortNumber();
		boost::asio::io_service ioService;
		boost::asio::ip::tcp::socket socket;

	private:

		const unsigned short portNumber;

	};

}

#endif