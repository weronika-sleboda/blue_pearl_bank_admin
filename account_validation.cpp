#include "account_validation.h"
#include "database.h"

namespace blue_pearl_bank_admin
{

	AccountValidation::AccountValidation(std::string theUserInfo) :

		userInfo { theUserInfo },
		firstName { "" },
		lastName { "" },
		emailAddress { "" },
		password { "" }

	{
	
		splitUserInfo();
	
	}

	void AccountValidation::splitUserInfo()
	{

		int nextSplitIndex { 0 };

		for (int index = 0; index < userInfo.length(); index++)
		{

			// '?' sign was added after each account field
			// so it's possible to know when to split the string 

			if (userInfo[index] == '?')
			{

				nextSplitIndex = index + 1;
				break;

			}

			firstName += userInfo[index];

		}

		for (int index = nextSplitIndex; index < userInfo.length(); index++)
		{

			if (userInfo[index] == '?')
			{

				nextSplitIndex = index + 1;
				break;

			}

			lastName += userInfo[index];

		}

		for (int index = nextSplitIndex; index < userInfo.length(); index++)
		{

			if (userInfo[index] == '?')
			{

				nextSplitIndex = index + 1;
				break;

			}

			emailAddress += userInfo[index];

		}

		for (int index = nextSplitIndex; index < userInfo.length(); index++)
		{

			if (userInfo[index] == '\n')
			{

				break;

			}

			password += userInfo[index];

		}

	}

	bool AccountValidation::emailAddressAlreadyExists()
	{
		Database::retriveLogIn(emailAddress);

		std::string receivedData = Database::getCovetedInfo();
		receivedData.pop_back();

		int matches { 0 };
		
		for (int index = 0; index < emailAddress.length(); index++)
		{

			if (emailAddress[index] == receivedData[index])
			{

				matches++;

			}

		}

		if (matches == emailAddress.length() - 1)
		{

			return true;

		}

		return false;

	}

	bool AccountValidation::validAccount()
	{

		if
		(
			validFirstName() &&
			validLastName() &&
			validEmailAddress() &&
			validPassword()

		)
		{

			return true;

		}

		return false;

	}

	bool AccountValidation::validFirstName()
	{

		if (firstName.length() <= 30 && firstName.length() > 0)
		{

			return true;

		}

		return false;

	}

	bool AccountValidation::validLastName()
	{

		if (lastName.length() <= 30 && lastName.length() > 0)
		{

			return true;

		}

		return false;

	}

	bool AccountValidation::validEmailAddress()
	{

		// Checking if the data is an actual email:

		for (int index = 0; index < emailAddress.length(); index++)
		{

			int splitIndex;
			if (emailAddress[index] == '@')
			{

				splitIndex = index + 2;

				for 
				(
					int secondPartIndex = splitIndex; 
					secondPartIndex < emailAddress.length();
					secondPartIndex++

				)
				{
		
					if (emailAddress[secondPartIndex] == '.')
					{

						return true;

						// It's just a simplified way to
						// check if email is valid and 
						// it won't solve every problem
						// but it's enough for a portfolio app

					}

				} // End of second for-loop

			} // End of first for-loop

		}

		return false;

	}

	bool AccountValidation::validPassword()
	{

		if (password.length() < 30 && password.length() > 6)
		{

			return true;

		}

		return false;

	}

	std::string AccountValidation::getFirstName()
	{

		return firstName;

	}

	std::string AccountValidation::getLastName()
	{

		return lastName;

	}

	std::string AccountValidation::getEmailAddress()
	{

		return emailAddress;

	}

	std::string AccountValidation::getPassword()
	{

		return password;

	}

}