#include "Paddle.h"

Paddle::Paddle()
{

}

void Paddle::Update()
{
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        if (mPaddleX > 0)
        {
            mPaddleX -= mPaddleSpeed;
        }
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        if (mPaddleX + mPaddleWidth < GetScreenWidth())
        {
            mPaddleX += mPaddleSpeed;
        }
    }

}

void Paddle::Draw()
{
    DrawRectangle(mPaddleX, mPaddleY, mPaddleWidth, mPaddleHeight, mPaddleColor);
}

void Paddle::Bonus(bool paddleBonus)
{
    if (paddleBonus == true)
    {
        mPaddleWidth += 50;
    }
    else
    {
        mPaddleSpeed += 4;
    }
}

void Paddle::BackBonus(bool paddleBonus)
{
    if(paddleBonus == true)
    {
        mPaddleWidth -= 50;
    }
    else 
    {
        mPaddleSpeed -= 4;
    }
}