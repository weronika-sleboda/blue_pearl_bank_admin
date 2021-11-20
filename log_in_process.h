#ifndef LOG_IN_PROCESS_H
#define LOG_IN_PROCESS_H

#include <wx/wx.h>
#include "log_in_validation.h"

namespace blue_pearl_bank_admin
{

	class LogInProcess
	{

	public:

		void run(wxStaticText& messagePanel);

	private:

		LogInValidation logInValidation;

	};

}

#endif