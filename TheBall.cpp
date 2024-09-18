#include "TheBall.h"

TheBall::TheBall()
{

}

void TheBall::Start()
{
	mBallCenterX = GetScreenWidth() / 2;
	mBallCenterY = GetScreenHeight() / 1.5;
	mBallRadius = 25;
	mBallColor = RED;
	mBallSpeedX = 300 ;
	mBallSpeedY = 300 ;
}

void TheBall::Update(Paddle& paddle)
{
	Paddle* newPaddle = &paddle;
	if (IsKeyDown(KEY_SPACE))
	{
		mBallLunch = true;
	}

	if (mBallLunch)
	{
		mBallCenterX += mBallSpeedX * GetFrameTime();
		if ((mBallCenterX >= GetScreenWidth() - mBallRadius / 2 && mBallSpeedX > 0) || (mBallCenterX <= mBallRadius / 2 && mBallSpeedX < 0))
		{
			mBallSpeedX *= -1;
		}

		mBallCenterY += mBallSpeedY * GetFrameTime();
		if ((mBallCenterY >= GetScreenHeight() - mBallRadius / 2 && mBallSpeedY > 0) || (mBallCenterY <= mBallRadius / 2 && mBallSpeedY < 0))
		{
			mBallSpeedY *= -1;
		}
	}
	else
	{
		DrawText("Press space for start", 250,400, 50, WHITE);
		mBallSpeedX = 300;
		mBallSpeedY = -300;
		mBallCenterX = GetScreenWidth() / 2;
		mBallCenterY = GetScreenHeight() / 1.5;

		mBallLunch = false;

		mBallCenterX = newPaddle->mPaddleX + newPaddle->mPaddleWidth / 2;
		mBallCenterY = newPaddle->mPaddleY - 10 - mBallRadius;
	}
}


void TheBall::Draw() 
{
	DrawCircle(mBallCenterX, mBallCenterY, mBallRadius, mBallColor);
}

void TheBall::CollideBrick()
{
	mBallSpeedX *= -1;
	mBallSpeedY *= -1;
}