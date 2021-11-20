#include "account.h"

namespace blue_pearl_bank_admin
{

	Account::Account
	(
	
		std::string theFirstName,
		std::string theLastName,
		std::string theEmailAddress,
		std::string thePassword
	
	) 
		
		:

		firstName { theFirstName },
		lastName { theLastName },
		emailAddress { theEmailAddress },
		password { thePassword },
		funds{ 0 }

	{}

	const std::string Account::getFirstName()
	{

		return firstName;

	}

	const std::string const Account::getLastName()
	{

		return lastName;

	}

	const std::string Account::getEmailAddress()
	{

		return emailAddress;

	}

	const std::string Account::getPassword()
	{

		return password;

	}

	const std::string Account::getFunds()
	{

		return std::to_string(funds);

	}

	bool Account::depositFunds(long long amount)
	{

		long long maxAmount { 999999999 };

		if (amount < maxAmount)
		{

			if (amount + funds < maxAmount)
			{

				funds += amount;
				return true;

			}

		}
	
		return false;

	}

	bool Account::withdrawawFunds(long long amount)
	{

		if (amount >= funds)
		{

			funds -= amount;
			return true;

		}

		return false;

	}

}