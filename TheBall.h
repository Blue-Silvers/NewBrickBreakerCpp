#pragma once
#include "raylib.h"

class TheBall
{
private :
	float mBallCenterX = GetScreenWidth() / 2;
	float mBallCenterY = GetScreenHeight() / 2;
	int mBallRadius = 20;
	Color mBallColor = RED;
	float mBallSpeedX = 10;
	float mBallSpeedY = 10;
	bool mBallLunch = false;

public :
	TheBall();
	void Update();
	void Start();
	void Draw();
};

