#include "Bullet.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

Bullet::Bullet()
{
}

Bullet::Bullet(int BulletX, int BulletY) : BulletX(BulletX), BulletY(BulletY)
{
}


Bullet::~Bullet()
{
}

void Bullet::LoadBulletBitmap()
{
	wxStandardPaths &stdpaths = wxStandardPaths::Get();
	wxString fileLocation = stdpaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\bullet.jpg");
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);
	this->bulletBitmap = new wxBitmap(image);
}

void Bullet::BulletMove(int yAmount)
{
	this->BulletY += yAmount;
}

/*void Bullet::BulletIntersect(Alien * alien)
{
}*/


int Bullet::BulletGetX()
{
	return this->BulletX;
}

int Bullet::BulletGetY()
{
	return this->BulletY;
}

void Bullet::BulletSetY(int BulletY)
{
	this->BulletY = BulletY;
}

