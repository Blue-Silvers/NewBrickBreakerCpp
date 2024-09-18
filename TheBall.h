#pragma once
#include "raylib.h"
#include "Paddle.h"

class TheBall
{
private :
	Color mBallColor = RED;
	float mBallSpeedX = 10;
	float mBallSpeedY = 10;
	float mBallSpeedMax = 300;
	bool mBallLunch = false;
	Paddle* newPaddle;

public :
	float mBallCenterX = GetScreenWidth() / 2;
	float mBallCenterY = GetScreenHeight() / 2;
	int mBallRadius = 20;
	int mBallLife = 3;
	TheBall();
	void Update();
	void Start(Paddle& paddle);
	void Draw();
	void CollideBrick();
};

