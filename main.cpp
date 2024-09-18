#include "raylib.h"
#include <iostream>
#include "TheBall.h"
#include "Paddle.h"
#include "Brick.h"
#include "Bonus.h"


using namespace std;

    void Start();
    void NextStage();
    void ReStart();
    void Update();
    void Draw();
    void End();

TheBall theBall;
Paddle player;
int column = 10;
int row = 5;
int nbBrick = 0;
Brick theWall[14][10];
Bonus bonus[14][10];
int score = 0;
Font ft;

int main() {

    Start();

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    End();
    return 0;
}

void Start()
{
    InitWindow(1200, 800, "Pong Ping");
    SetTargetFPS(60);
    ft = LoadFont("resources/fonts/jupiter_crash.png");

    theBall.Start(player);

    column = 10;
    row = 5;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            theWall[i][j].Start(i, j, theBall);
            nbBrick += 1;
        }
    }

}

void Update() 
{
    theBall.Update();
    player.Update();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int returnBrick = theWall[i][j].Update();
            if (returnBrick == 0 || returnBrick == 1)
            {
                theBall.CollideBrick();
                score += 100;
                nbBrick -= returnBrick;
                int random = rand() % 10;
                if (random == 5)
                {
                    bonus[i][j].Start(theWall[i][j].mBrickX, theWall[i][j].mBrickY, theWall[i][j].mBrickWidth, theWall[i][j].mBrickHeight);
                }
            }
            if (bonus[i][j].Update(player))
            {
                player.Bonus(bonus[i][j].mPaddleBonus);
                score += 200;
            }
            if (bonus[i][j].Time() == true)
            {
                player.BackBonus(bonus[i][j].mPaddleBonus);
            }
        }
    }

    if (theBall.mBallLife < 0)
    {
        ReStart();
    }

    if (nbBrick == 0) 
    {
        NextStage();
    }
}

void Draw()
{
    BeginDrawing();

    ClearBackground(DARKBLUE);
    theBall.Draw();
    player.Draw();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            theWall[i][j].Draw();
            bonus[i][j].Draw();
        }
    }


    DrawTextEx(ft, TextFormat("%08i", score), Vector2{(float)(GetScreenWidth() / 2.3), 5 }, 50, 5, WHITE);
    DrawTextEx(ft, TextFormat("Bricks : %02i", nbBrick), Vector2{ 5, 5 }, 50, 5, WHITE);
    DrawTextEx(ft, TextFormat("Life : %01i", theBall.mBallLife), Vector2 { (float)(GetScreenWidth() - 150), 5 }, 50, 5, WHITE);
    EndDrawing();
}

void ReStart()
{
    theBall.Start(player);
    nbBrick = 0;
    column = 10;
    row = 5;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            theWall[i][j].Start(i, j, theBall);
            nbBrick += 1;
        }
    }
    score = 0;
}

void NextStage()
{
    int newLife = theBall.mBallLife + 1;
    theBall.Start(player);
    theBall.mBallLife = newLife;
    row += 2;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            theWall[i][j].Start(i, j, theBall);
            nbBrick += 1;
        }
    }
}

void End()
{
    CloseWindow();
}