#pragma once
#include "wx\dcbuffer.h"
class Alien
{
public:
	Alien();
	Alien(int AlienX, int AlienY);
	void LoadAlienBitmap();
	void AlienMove(int Yammount, int maxY, int direction);
	int AlienGetX();
	int AlienGetY();
	wxBitmap *alienBitmap = nullptr;
	~Alien();
private: 
	int AlienX;
	int AlienY;
	int AlienNum;
};