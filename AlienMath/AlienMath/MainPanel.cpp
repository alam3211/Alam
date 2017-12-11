#include "MainPanel.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

BEGIN_EVENT_TABLE(MainPanel, wxPanel)
	EVT_BUTTON(1001, MainPanel::OnBackButtonClick)
	EVT_PAINT(MainPanel::OnPaint)
END_EVENT_TABLE()


MainPanel::MainPanel(AlienMathFrame * parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	this->LoadBackgroundBitmap();
	this->LoadPlay();
	wxButton* backButton = new wxButton(this, 1001, wxT("Back"), wxPoint(320, 600), wxDefaultSize);
}


MainPanel::~MainPanel()
{
}

void MainPanel::OnBackButtonClick(wxCommandEvent & event)
{
//	this->parentFrame->gamePanel->timer->Start(150);
	this->parentFrame->ShowGamePanel();
}
void MainPanel::LoadBackgroundBitmap()
{
	wxStandardPaths &stdpaths = wxStandardPaths::Get();
	wxString fileLocation = stdpaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\background.jpg");
	//wxMessageOutputDebug().Pritf("")
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);
	this->backgroundBitmap = new wxBitmap(image);
}
void MainPanel::LoadPlay()
{
	wxStandardPaths &stdpaths = wxStandardPaths::Get();
	wxString fileLocation = stdpaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\button.png");
	//wxMessageOutputDebug().Pritf("")
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	this->playbtn = new wxBitmap(image);
}

void MainPanel::OnPaint(wxPaintEvent & event) {
	wxPaintDC pdc(this);
	if (backgroundBitmap != nullptr)
		pdc.DrawBitmap(*backgroundBitmap, wxPoint(0, 0), true);
	if (playbtn != nullptr)
		pdc.DrawBitmap(*playbtn, wxPoint(320, 690), true);

}
