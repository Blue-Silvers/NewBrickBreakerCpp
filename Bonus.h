#pragma once
#include "raylib.h"
#include "Paddle.h"
class Bonus
{
private:
	float mBallSpeedY = 2;
	
	bool mBallCollide = true;
	bool mBonusCountDown = false;
	int mBonusTime = 1000;
	Paddle* newPaddle;

public:
	int mBallRadius = 8;
	float mBallX = 100;
	float mBallY = 100;
	Color mBallColor = WHITE;
	bool mPaddleBonus = true;
	Bonus();
	void Start(int posX, int posY, int brickWidth, int brickHeight);
	bool Update(Paddle paddle);
	void Draw();
	bool Time();
};