#include "Alien.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

Alien::Alien()
{
}

Alien::Alien(int AlienX, int AlienY):AlienX(AlienX), AlienY(AlienY)
{
}

void Alien::LoadAlienBitmap()
{
	wxStandardPaths &stdpaths = wxStandardPaths::Get();
	wxString fileLocation = stdpaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\enemy.jpg");
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);
	this->alienBitmap = new wxBitmap(image);
}

void Alien::AlienMove(int Yammount, int maxY, int direction)
{
	//if (this->AlienY + Yammount * direction > maxY || this->AlienY + Yammount * direction < 0) {
		//AlienY -= Yammount;
	//}
	//else 
	this->AlienY += Yammount * direction;
}

int Alien::AlienGetX()
{
	return this->AlienX;
}

int Alien::AlienGetY()
{
	return this->AlienY;
}

Alien::~Alien()
{
}
