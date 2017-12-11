#pragma once
#include "wx\dcbuffer.h"

class Bullet
{
public:
	Bullet();
	Bullet(int BulletX, int BulletY);
	~Bullet();
	wxBitmap *bulletBitmap = nullptr;
	void LoadBulletBitmap();
	void BulletMove(int yAmount);
	int BulletGetX();
	int BulletGetY();
	void BulletSetY(int BulletY);
private:
	int BulletX;
	int BulletY;
};

