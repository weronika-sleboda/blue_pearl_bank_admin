#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>
#include "colour_palette.h"

namespace blue_pearl_bank_admin
{

	class MainFrame : public wxFrame
	{

	public:

		MainFrame();

	private:

		void setUpTitlePanel();
		void setupMessagePanel();
		void setupRunButton();
		void setupAuthorInfo();
		void activateRunButton();
		void showWaitForConnectionMessage();

		//*** Button Action

		void onClickRunServer(wxCommandEvent& event);

	private:

		ColourPalette colour;
		bool buttonClicked;

	private:

		//*** Title Panel

		wxPanel titleBorderPanel;
		wxPanel titlePanel;
		wxStaticText title;

		//*** MessagePanel

		wxPanel messageBorderPanel;
		wxPanel messagePanel;
		wxStaticText message;

		//*** Button

		wxButton runButton;

		//*** Author Info

		wxStaticText authorInfo;


	};

}

#endif