#include "AlienMathFrame.h"
#include "MainPanel.h"
#include "AlienMathWindow.h"
AlienMathFrame::AlienMathFrame(const wxString & title)
	: wxFrame(NULL, wxID_ANY, title)
{
	this->InitComponents();
}

void AlienMathFrame::fitWindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(640, 720));
	this->Layout();
}

void AlienMathFrame::InitComponents()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);

	this->mainPanel = new MainPanel(this);
	this->mainPanel->Show(false);
	this->boxSizer->Add(mainPanel, 1, wxEXPAND, 0);

	this->gamePanel = new AlienMathWindow(this);
	this->gamePanel->Show(false);
	this->boxSizer->Add(gamePanel, 1, wxEXPAND, 0);

	SetSizer(boxSizer);

	ShowMainPanel();
}

void AlienMathFrame::ShowMainPanel()
{
	this->mainPanel->Show(true);
	this->gamePanel->Show(false);
	
	fitWindowSize();
}

void AlienMathFrame::ShowGamePanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(true);
	
	fitWindowSize();

}