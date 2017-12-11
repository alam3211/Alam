#pragma once
#include "Bullet.h"
#include "Alien.h"

class Plane
{
public:
	Plane();
	wxBitmap *planeBitmap = nullptr;
	Plane(int PlaneX, int PlaneY) : PlaneX(PlaneX), PlaneY(PlaneY)
	{
	}
	void PlaneMove(int Xammount,int maxX, int direction);
	void PlaneShootBullet();
	void LoadPlanetBitmap();
	void PlaneReload();
	int PlaneGetAmmo();
	bool BulletIntersect(Alien *alien);
	bool AlienIntersect(Alien *alien);
	int PlaneGetX();
	int PlaneGetY();
	~Plane();
	Bullet *bullet;
private:
	int PlaneX;
	int PlaneY;
	int PlaneAmmo=1;
};

