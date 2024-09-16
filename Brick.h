#pragma once
#include "raylib.h"
#include "TheBall.h"
class Brick
{
private:

	Color mBrickColor = WHITE;

	int mBrickRow = 0;
	int mBrickColumn = 0;

public:
	int mBrickLife = 2;
	float mBrickX = 100;
	float mBrickY = 100;
	float mBrickWidth = 100;
	float mBrickHeight = 20;
	Brick();
	bool Update(TheBall ball);
	void Draw();
	void Start(int row, int column);
	void SetColor(int row);
};