#ifndef MAIN_APPLICATION_H
#define MAIN_APPLICATION_H

#include <wx/wx.h>

namespace blue_pearl_bank_admin
{

	class MainApplication : public wxApp
	{

	public:

		virtual bool OnInit() override;

	};

}

#endif