#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>
#include "account.h"

namespace blue_pearl_bank_admin
{

	class Database
	{

	public:

		static bool createDatabase();
		static bool addAccount(Account account);

		static bool updateFunds
		(std::string givenEmail, std::string newFunds);

		static bool retriveAccount(std::string& givenEmail);
		static bool retriveFirstName(std::string& givenEmail);
		static bool retriveLastName(std::string& givenEmail);
		static bool retriveLogIn(std::string& givenEmail);
		static bool retriveFunds(std::string& givenEmail);

		static std::string getCovetedInfo();

	private:

		Database() = delete;
		Database(Database&) = delete;
		Database(Database&&) = delete;
		Database& operator=(Database&) = delete;
		Database&& operator=(Database&&) = delete;

	private:

		static int callback
		(

			void* unused,
			int numberOfArguments,
			char** values,
			char** columnName

		);

	private:

		static std::string covetedInfo;

	private:

		static sqlite3* database;
		static const char* const databaseDirectory;
		static const std::string const tableName;
		static const std::string const firstNameColumn;
		static const std::string const lastNameColumn;
		static const std::string const emailAddressColumn;
		static const std::string const passwordColumn;
		static const std::string const fundsColumn;

	};

}

#endif