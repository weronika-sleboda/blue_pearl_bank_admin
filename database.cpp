#include "database.h"
#include <fstream>
#include <iostream>

namespace blue_pearl_bank_admin
{

	std::string Database::covetedInfo = { "" };

	sqlite3* Database::database;

	const char* const Database::databaseDirectory =
	{ "C:\\Users\\weron\\source\\repos\\blue_pearl_bank_admin\\Database\\accounts.db" };

	const std::string const Database::tableName = { "ACCOUNTS" };
	const std::string const Database::firstNameColumn = { "FIRST_NAME" };
	const std::string const Database::lastNameColumn = { "LAST_NAME" };
	const std::string const Database::emailAddressColumn = { "EMAIL_ADDRESS" };
	const std::string const Database::passwordColumn = { "PASSWORD" };
	const std::string const Database::fundsColumn = { "FUNDS" };

	bool Database::createDatabase()
	{

		try
		{

			sqlite3_open(databaseDirectory, &database);

			const std::string const createTable =
			{

				"CREATE TABLE IF NOT EXISTS " + tableName + " ("
				"ID INTEGER PRIMARY KEY AUTOINCREMENT, " +
				firstNameColumn + " TEXT NOT NULL, " +
				lastNameColumn + " TEXT NOT NULL, " +
				emailAddressColumn + " TEXT NOT NULL, " +
				passwordColumn + " TEXT NOT NULL, " +
				fundsColumn + " TEXT NOT NULL);"

			};

			sqlite3_exec
			(database, createTable.c_str(), callback, NULL, NULL);

			sqlite3_close(database);

			return true;

		}


		catch (std::exception error)
		{

			return false;

		}

	}

	bool Database::addAccount(Account account)
	{

		try
		{

			sqlite3_open(databaseDirectory, &database);

			std::string addAccount =
			{

				"INSERT INTO " + tableName + " (" + 
				firstNameColumn + ", " + 
				lastNameColumn + ", " +
				emailAddressColumn + ", " +
				passwordColumn + ", " +
				fundsColumn + ") " +
				"VALUES (" +
				"'" + account.getFirstName() + "', " +
				"'" + account.getLastName() + "', " +
				"'" + account.getEmailAddress() + "', " +
				"'" + account.getPassword() + "', " +
				"'" + account.getFunds() + "');"

			};

			sqlite3_exec(database, addAccount.c_str(), callback, NULL, NULL);

			//sqlite3_close(database);

			return true;

		}

		catch (std::exception error)
		{

			return false;

		}

	}

	bool Database::updateFunds
	(std::string givenEmail, std::string newFunds)
	{
		try
		{

			sqlite3_open(databaseDirectory, &database);

			std::string update =
			{

				"UPDATE " + tableName + " "
				"SET " + fundsColumn + " "
				" = '" + newFunds + "';"
				"WHERE " + emailAddressColumn + " LIKE "
				"'%" + givenEmail + "%'"

			};

			sqlite3_exec(database, update.c_str(), callback, NULL, NULL);

			sqlite3_close(database);

			return true;

		}

		catch (std::exception error)
		{

			return false;

		}

	}

	bool Database::retriveAccount(std::string& givenEmail)
	{

		try
		{

			sqlite3_open(databaseDirectory, &database);

			std::string find =
			{

				"SELECT " + 
				firstNameColumn + ", " +
				lastNameColumn + ", " +
				emailAddressColumn + ", " +
				fundsColumn + " " +
				"FROM " + tableName + " " +
				"WHERE " + emailAddressColumn + " LIKE " +
				"'%" + givenEmail + "%'; "

			};

			sqlite3_exec(database, find.c_str(), callback, NULL, NULL);

			sqlite3_close(database);

			return true;

		}

		catch (std::exception error)
		{

			return false;

		}

	}

	bool Database::retriveFirstName(std::string& givenEmail)
	{

		try
		{

			sqlite3_open(databaseDirectory, &database);

			std::string find =
			{

				"SELECT " + firstNameColumn + " " +
				"FROM " + tableName + " " +
				"WHERE " + emailAddressColumn + " LIKE " +
				"'%" + givenEmail + "%'; "

			};

			sqlite3_exec(database, find.c_str(), callback, NULL, NULL);

			sqlite3_close(database);

			return true;

		}

		catch (std::exception error)
		{

			return false;

		}

	}


	bool Database::retriveLastName(std::string& givenEmail)
	{

		try
		{

			sqlite3_open(databaseDirectory, &database);

			std::string find =
			{

				"SELECT " + lastNameColumn + " " +
				"FROM " + tableName + " " +
				"WHERE " + emailAddressColumn + " LIKE " +
				"'%" + givenEmail + "%'; "

			};

			sqlite3_exec(database, find.c_str(), callback, NULL, NULL);

			sqlite3_close(database);

			return true;

		}

		catch (std::exception error)
		{

			return false;

		}

	}

	bool Database::retriveLogIn(std::string& givenEmail)
	{

		try
		{

			sqlite3_open(databaseDirectory, &database);

			std::string find =
			{

				"SELECT " + emailAddressColumn +
				", " + passwordColumn + " "
				"FROM " + tableName + " " +
				"WHERE " + emailAddressColumn + " LIKE " +
				"'%" + givenEmail + "%';"

			};

			sqlite3_exec(database, find.c_str(), callback, NULL, NULL);

			sqlite3_close(database);

			return true;

		}

		catch (std::exception error)
		{

			return false;

		}

	}

	bool Database::retriveFunds(std::string& givenEmail)
	{

		try
		{

			sqlite3_open(databaseDirectory, &database);

			std::string find =
			{

				"SELECT " + fundsColumn + " " +
				"FROM " + tableName + " " +
				"WHERE " + emailAddressColumn + " LIKE " +
				"'%" + givenEmail + "%'; "

			};

			sqlite3_exec(database, find.c_str(), callback, NULL, NULL);

			sqlite3_close(database);

			return true;

		}

		catch (std::exception error)
		{

			return false;

		}

	}

	std::string Database::getCovetedInfo()
	{

		return covetedInfo;

	}

	int Database::callback
	(

		void* unused,
		int numberOfArguments,
		char** values,
		char** columnName

	)
	{

		covetedInfo = "";

		for (int index = 0; index < numberOfArguments; index++)
		{

			covetedInfo += values[index];
			covetedInfo += "\n";

		}

		return 0;

	}
}