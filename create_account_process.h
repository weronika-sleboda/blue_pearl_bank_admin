#ifndef CREATE_ACCOUNT_PROCESS_H
#define CREATE_ACCOUNT_PROCESS_H

#include <wx/wx.h>
#include "account_validation.h"

namespace blue_pearl_bank_admin
{

	class CreateAccountProcess
	{

	public:

		void run(wxStaticText& messagePanel);

	private:

		void createAccount
		(wxStaticText& messagePanel, AccountValidation& validation);

		const std::string getUserData();

		const std::string getError
		(wxStaticText& messagePanel, AccountValidation& validation);

	};

}

#endif