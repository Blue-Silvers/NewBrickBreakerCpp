#include "TheBall.h"

TheBall::TheBall()
{

}

void TheBall::Start()
{
	mBallCenterX = GetScreenWidth() / 2;
	mBallCenterY = GetScreenHeight() / 2;
	mBallRadius = 25;
	mBallColor = YELLOW;
	mBallSpeedX = 10;
	mBallSpeedY = 10;
}

void TheBall::Update() 
{
	mBallCenterX += mBallSpeedX;
	if ((mBallCenterX >= GetScreenWidth() - mBallRadius / 2 && mBallSpeedX >0) || (mBallCenterX >= mBallRadius / 2 && mBallSpeedX < 0))
	{
		mBallSpeedX *= -1;
	}

	mBallCenterY += mBallSpeedY;
	if ((mBallCenterY >= GetScreenWidth() - mBallRadius / 2 && mBallSpeedY > 0) || (mBallCenterY >= mBallRadius / 2 && mBallSpeedY < 0))
	{
		mBallSpeedY *= -1;
	}
}

void TheBall::Draw() 
{
	DrawCircle(mBallCenterX, mBallCenterY, mBallRadius, mBallColor);
}