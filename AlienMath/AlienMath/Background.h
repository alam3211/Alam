#pragma once
#include <wx\dcbuffer.h>
#include <wx/window.h>
class Background
{
	private:
		int x;
		int y;
	public:
		Background();
		Background(int x, int y);
		void Draw(wxBufferedPaintDC &dc);
		~Background();
};

