#pragma once
#include "wx\wx.h"
#include "wx\dcbuffer.h"
#include "AlienMathFrame.h"
class MainPanel : public wxPanel
{
public:
	MainPanel(AlienMathFrame* parent);
	~MainPanel();
	void OnPaint(wxPaintEvent &event);
	void LoadBackgroundBitmap();
	void LoadPlay();
	void OnBackButtonClick(wxCommandEvent& event);
	wxBitmap *backgroundBitmap = nullptr;
	wxBitmap *playbtn = nullptr;
private:
	AlienMathFrame *parentFrame;
	DECLARE_EVENT_TABLE()

};

