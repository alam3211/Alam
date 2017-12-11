#include "Background.h"



Background::Background()
{
}

Background::Background(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Background::Draw(wxBufferedPaintDC & dc)
{
	dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColour(*wxWHITE)));
	dc.DrawRectangle(this->x, this->y,640,720); // sini salah 
}


Background::~Background()
{
}
