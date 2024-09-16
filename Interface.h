#pragma once
#include "raylib.h"

class Interface
{
private:
	bool mStartScren = true;
	float mTime = 0;

public:
	bool mWin = false;
	bool mGameOver = false;
	Interface();
	bool Update(int life);
	void Draw(Font ft, int score);
};

