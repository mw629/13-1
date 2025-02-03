#pragma once
class Enemy
{
private:
	int posX_;
	int posY_;
	int velocityX_;

	int radius_;
public:
	static bool isAlive;

	Enemy();

	void UpDate(char (&keys)[],int bulletPosX, int bulletPosY,int bulletRadius, bool isShot);
	void Draw();

	int SetPosX(int posX) { return posX_ = posX; }

};

