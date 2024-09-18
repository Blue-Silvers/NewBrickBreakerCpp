#pragma once
#include "raylib.h"
#include "Paddle.h"

class TheBall
{
private :
	Color mBallColor = RED;
	float mBallSpeedX = 10;
	float mBallSpeedY = 10;
	bool mBallLunch = false;

public :
	float mBallCenterX = GetScreenWidth() / 2;
	float mBallCenterY = GetScreenHeight() / 2;
	int mBallRadius = 20;
	TheBall();
	void Update(Paddle& paddle);
	void Start();
	void Draw();
	void CollideBrick();
};

