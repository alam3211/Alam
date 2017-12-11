#pragma once
#include "wx/wx.h"
class MainPanel;
class AlienMathWindow;

class AlienMathFrame : public wxFrame {
public:
	wxBoxSizer* boxSizer;
	MainPanel* mainPanel;
	AlienMathWindow* gamePanel;

	void fitWindowSize();
	AlienMathFrame(const wxString &title);
	void InitComponents();
	void ShowMainPanel();
	void ShowGamePanel();
	//void ShowBluePanel();
};