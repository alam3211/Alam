#include "wx\wx.h"
#include "AlienMathFrame.h"
class MyApp :public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)
bool MyApp::OnInit()
{
	AlienMathFrame *frame = new AlienMathFrame("~Alien Math~");
	frame->Show(true);
	return true;
}