#include "TheBall.h"

TheBall::TheBall()
{

}

void TheBall::Start()
{
	mBallCenterX = GetScreenWidth() / 2;
	mBallCenterY = GetScreenHeight() / 4;
	mBallRadius = 25;
	mBallColor = RED;
	mBallSpeedX = 300 ;
	mBallSpeedY = 300 ;
}

void TheBall::Update() 
{
	
	if (IsKeyDown(KEY_LEFT) && mBallSpeedX > 0)
	{
		mBallSpeedX *= -1;
	}
	else if (IsKeyDown(KEY_RIGHT) && mBallSpeedX < 0)
	{
		mBallSpeedX *= -1;
	}
	else if (IsKeyDown(KEY_UP) && mBallSpeedY > 0)
	{
		mBallSpeedY *= -1;
	}
	else if (IsKeyDown(KEY_DOWN) && mBallSpeedY < 0)
	{
		mBallSpeedY *= -1;
	}

	mBallCenterX += mBallSpeedX * GetFrameTime();
	if ((mBallCenterX >= GetScreenWidth() - mBallRadius / 2 && mBallSpeedX > 0) || (mBallCenterX <= mBallRadius / 2 && mBallSpeedX < 0))
	{
		mBallSpeedX *= -1;
	}

	mBallCenterY += mBallSpeedY * GetFrameTime();
	if ((mBallCenterY >= GetScreenWidth() - mBallRadius / 2 && mBallSpeedY > 0) || (mBallCenterY <= mBallRadius / 2 && mBallSpeedY < 0))
	{
		mBallSpeedY *= -1;
	}


}

void TheBall::Draw() 
{
	DrawCircle(mBallCenterX, mBallCenterY, mBallRadius, mBallColor);
}