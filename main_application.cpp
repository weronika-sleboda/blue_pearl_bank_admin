#include "main_application.h"
#include "frame_controller.h"

namespace blue_pearl_bank_admin
{

	wxIMPLEMENT_APP(MainApplication);

	bool MainApplication::OnInit()
	{

		FrameController::frameController().showMainFrame();

		return true;

	}

}