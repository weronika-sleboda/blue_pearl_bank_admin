#include "main_frame.h"
#include <thread>
#include "frame_controller.h"
#include "database.h"
#include "account.h"
#include "log_in_process.h"
#include "create_account_process.h"
#include "network_controller.h"
#include "account_validation.h"

namespace blue_pearl_bank_admin
{

	MainFrame::MainFrame() :

		wxFrame
	{

		nullptr,
		wxID_ANY,
		"Blue Pearl Bank Admin",
		wxPoint { 500, 10 },
		wxSize { 700, 500 }

	},

		titleBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 20 },
		wxSize { 640, 60 }

	},

		titlePanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 23 },
		wxSize { 634, 54 }

	},

		title
	{

		this,
		wxID_ANY,
		"BLUE PEARL BANK ADMIN",
		wxPoint { 125, 30 },
		wxSize { 200, 40 }

	},

		messageBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 110 },
		wxSize { 640, 240 }

	},

		messagePanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 113 },
		wxSize { 633, 234 }

	},

		message
	{

		this,
		wxID_ANY,
		"Run server in order to use the application.",
		wxPoint { 40, 130 },
		wxSize { 615, 200 }

	},

		runButton
	{

		this,
		wxID_ANY,
		"RUN SERVER",
		wxPoint { 19, 380 },
		wxSize { 642, 30 }

	},

		authorInfo
	{

		this,
		wxID_ANY,
		"2021 Weronika Sleboda",
		wxPoint { 25, 430 },
		wxSize { 440, 20 }

	},

		buttonClicked{ false }


		//*** Constructor Body

	{

		SetBackgroundColour(colour.darkSteel);
		setUpTitlePanel();
		setupMessagePanel();
		setupRunButton();
		setupAuthorInfo();
		activateRunButton();

		Database::createDatabase();
		
	}

	void MainFrame::setUpTitlePanel()
	{

		wxFont font
		{

			25,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_LIGHT

		};

		titleBorderPanel.SetBackgroundColour(colour.steel);
		titlePanel.SetBackgroundColour(colour.galactic);
		title.SetBackgroundColour(colour.galactic);
		title.SetForegroundColour(colour.lightSteel);
		title.SetFont(font);

	}

	void MainFrame::setupMessagePanel()
	{

		wxFont font
		{

			14,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_LIGHT

		};

		messageBorderPanel.SetBackgroundColour(colour.lightSteel);
		messagePanel.SetBackgroundColour(colour.steel);
		message.SetBackgroundColour(colour.steel);
		message.SetForegroundColour(colour.lightSteel);
		message.SetFont(font);

	}

	void MainFrame::setupRunButton()
	{

		wxFont font
		{

			18,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_ITALIC,
			wxFONTWEIGHT_LIGHT

		};

		runButton.SetBackgroundColour(colour.lightSteel);
		runButton.SetForegroundColour(colour.darkSteel);
		runButton.SetFont(font);

	}

	void MainFrame::setupAuthorInfo()
	{

		wxFont font
		{

			10,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_ITALIC,
			wxFONTWEIGHT_LIGHT

		};

		authorInfo.SetForegroundColour(colour.lightSteel);
		authorInfo.SetFont(font);

	}

	void MainFrame::activateRunButton()
	{

		runButton.Bind
		(wxEVT_BUTTON, &MainFrame::onClickRunServer, this);

	}

	void MainFrame::onClickRunServer(wxCommandEvent& event)
	{

		if(!buttonClicked)
		{

			buttonClicked = true;

			showWaitForConnectionMessage();

			if (NetworkController::network().runServer())
			{

				message.SetLabel("Server is running.");

				while (true)
				{

					NetworkController::network().acquireData();

					std::string clientResponse =

						NetworkController::network().getClientData();

					clientResponse.pop_back();

					if (clientResponse == "CREATE_ACCOUNT")
					{

						CreateAccountProcess createAccountProcess;
						createAccountProcess.run(message);

					}

					if (clientResponse == "LOG_IN")
					{

						LogInProcess logInProcess;
						logInProcess.run(message);

					}

					if(clientResponse == "BANK_FRAME")
					{

						

					}
				}
			}

			else
			{

				message.SetLabel("Server is down.");
				event.Skip();

			}

		}

	}

	void MainFrame::showWaitForConnectionMessage()
	{

		std::string info = "Please wait, starting the server";

		runButton.Disable();

		for (int counter = 1; counter <= 8; counter++)
		{

			if (info == "Please wait, starting the server....")
			{

				info = "Please wait, starting the server";

			}

			message.SetLabel(info);
			info += ".";
			std::this_thread::sleep_for(std::chrono::milliseconds(600));

		}

	}

}