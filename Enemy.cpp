#include "Enemy.h"
#include <Novice.h>
#include <math.h>

Enemy::Enemy()
{
	posX_ = 100;
	posY_ = 300;
	velocityX_ = 10;

	radius_ = 50;
}



void Enemy::UpDate(char(&keys)[], int bulletPosX, int bulletPosY, int bulletRadius, bool isShot)
{
	float distance;

	if (keys[DIK_R])
	{
		isAlive = true;
	}

	posX_ += velocityX_;

	if (posX_ < 0 + radius_ || posX_ > 1280 - radius_)
	{
		velocityX_ *= -1;
	}

	distance = sqrtf(static_cast<float>((posX_ - bulletPosX) * (posX_ - bulletPosX) + (posY_ - bulletPosY) * (posY_ - bulletPosY)));

	if (distance < radius_ + bulletRadius && isShot)
	{
		isAlive = false;
	}

}

void Enemy::Draw()
{
	if (isAlive)
	{
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0, 0xff0000ff, kFillModeSolid);
	}
}
