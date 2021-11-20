#include "frame_controller.h"

namespace blue_pearl_bank_admin
{

	FrameController::FrameController() :

		mainFrame { new MainFrame { } }

	{}

	FrameController::~FrameController()
	{}

	FrameController& FrameController::frameController()
	{

		static FrameController controller;
		return controller;

	}

	void FrameController::showMainFrame()
	{

		mainFrame->Show();

	}

}