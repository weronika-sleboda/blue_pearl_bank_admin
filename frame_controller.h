#ifndef FRAME_CONTROLLER_H
#define FRAME_CONTROLLER_H

#include "main_frame.h"
#include <string>

namespace blue_pearl_bank_admin
{

	class FrameController
	{

	public:

		static FrameController& frameController();

	public:

		~FrameController();

	public:

		void showMainFrame();

	private:

		FrameController();
		FrameController(FrameController&) = delete;
		FrameController(FrameController&&) = delete;
		FrameController& operator=(FrameController&) = delete;
		FrameController& operator=(FrameController&&) = delete;

	private:

		MainFrame* mainFrame;

	};

}

#endif