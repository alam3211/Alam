#pragma once
#include "wx\wx.h"
#include "AlienMathFrame.h"
#define use_crt_secure_no_warnings
class Alien;
class Plane;
class Background;

WX_DECLARE_OBJARRAY(Alien*, AlienObjectArray);

class AlienMathWindow:public wxWindow
{
public:
	AlienMathWindow(wxFrame *parent);
	void OnPaint(wxPaintEvent &event);
	void OnKeyDown(wxKeyEvent &event);
	void OnKeyUP(wxKeyEvent &event);
	void OnTimer(wxTimerEvent &event);
	~AlienMathWindow();
	void Repaint();
	wxTimer *timer;
private:
	Plane *player;
	Background *bg;
	AlienObjectArray AlienArr;
	//wxBitmap *PlaneBitmap = nullptr;
	DECLARE_EVENT_TABLE();
	//void LoadPlaneBitmap();
};

