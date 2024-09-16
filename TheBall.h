#pragma once
#include "raylib.h"

class TheBall
{
private :
	int mBallCenterX = GetScreenWidth() / 2;
	int mBallCenterY = GetScreenHeight() / 2;
	float mBallRadius = 20;
	Color mBallColor = RED;
	int mBallSpeedX = 10;
	int mBallSpeedY = 10;

public :
	TheBall();
	void Update();
	void Start();
	void Draw();
};

