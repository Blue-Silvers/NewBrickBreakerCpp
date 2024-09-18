#include "TheBall.h"

TheBall::TheBall()
{

}

void TheBall::Start(Paddle& paddle)
{
	mBallCenterX = GetScreenWidth() / 2;
	mBallCenterY = GetScreenHeight() / 1.5;
	mBallRadius = 15;
	mBallColor = RED;
	mBallSpeedX = 300 ;
	mBallSpeedY = 300 ;
	newPaddle = &paddle;
}

void TheBall::Update()
{
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
		if (mBallCenterY <= mBallRadius / 2 && mBallSpeedY < 0)
		{
			mBallSpeedY *= -1;
		}
		else if (mBallCenterY + mBallRadius > GetScreenHeight())
		{
			mBallLunch = false;
			mBallLife -= 1;
		}

		if (mBallCenterY + mBallRadius >= newPaddle->mPaddleY && mBallCenterX + mBallRadius > newPaddle->mPaddleX && mBallCenterX - mBallRadius < newPaddle->mPaddleX + newPaddle->mPaddleWidth)
		{
			if (mBallCenterX > newPaddle->mPaddleX + newPaddle->mPaddleWidth / 2)
			{
				float distanceRight = newPaddle->mPaddleX + newPaddle->mPaddleWidth / 2 - mBallCenterX;
				mBallSpeedX = -mBallSpeedMax * (distanceRight / (newPaddle->mPaddleWidth / 2));
			}
			else if (mBallCenterX < newPaddle->mPaddleX + newPaddle->mPaddleWidth / 2)
			{
				float distanceLeft = newPaddle->mPaddleX + newPaddle->mPaddleWidth / 2 - mBallCenterX;
				mBallSpeedX = -mBallSpeedMax * (distanceLeft / (newPaddle->mPaddleWidth / 2));
			}
			else
			{
				mBallCenterX = 0;
			}
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
	mBallSpeedY *= -1;
}