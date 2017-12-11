#pragma once
class AlienObject
{
private:
	int alienNum;
	int alienSpeed;
	//int alienAcceleration;
	int alienPosX;
public:
	AlienObject();
	AlienObject(int alienPosX,int alienNum,int alienSpeed);
	void AlienMove(int Y);
	~AlienObject();
};

