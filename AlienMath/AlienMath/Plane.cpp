#include "Plane.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>


Plane::Plane()
{
}

void Plane::PlaneMove(int Xammount, int maxX, int direction)
{
	if (this->PlaneX + Xammount * direction > maxX-135 || this->PlaneX + Xammount * direction < 0) {
		this->PlaneX -= Xammount * direction;
	}
	else {
		this->PlaneX += Xammount * direction;
	}
}

bool Plane::BulletIntersect(Alien *alien)
{
	if (this->bullet->BulletGetY() < alien->AlienGetY()+110 ){
		//wxMessageOutputDebug().Printf("%d-%d-%d", alien->AlienGetX(), this->bullet->BulletGetX(), alien->AlienGetX() + 123);
		if (this->bullet->BulletGetX() >= alien->AlienGetX() && this->bullet->BulletGetX() <= alien->AlienGetX()+123 ) {
			return true;
		}
		return false;
	}
	return false;
}

bool Plane::AlienIntersect(Alien * alien)
{
	if (alien->AlienGetY()+135 > this->PlaneY) {
		return true;
	}
	return false;
}


void Plane::PlaneShootBullet()
{
	this->bullet = new Bullet(this->PlaneX + 60,this->PlaneY-20);
	this->PlaneAmmo = 0;
}

void Plane::LoadPlanetBitmap()
{
	wxStandardPaths &stdpaths = wxStandardPaths::Get();
	wxString fileLocation = stdpaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\player.jpg");
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);
	this->planeBitmap = new wxBitmap(image);
}

void Plane::PlaneReload()
{
	this->PlaneAmmo = 1;
}

int Plane::PlaneGetAmmo()
{
	return this->PlaneAmmo;
}

int Plane::PlaneGetX()
{
	return this->PlaneX;
}

int Plane::PlaneGetY()
{
	return this->PlaneY;
}

Plane::~Plane()
{
}

