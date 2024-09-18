#include "raylib.h"
#include <iostream>
#include "TheBall.h"
#include "Paddle.h"
#include "Brick.h"


using namespace std;

    void Start();
    void Update();
    void Draw();
    void End();

TheBall theBall;
Paddle player;
int column = 10;
int row = 5;
int nbBrick = 0;
Brick theWall[14][10];
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
            }
        }
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
        }
    }


    DrawTextEx(ft, TextFormat("%08i", score), Vector2{(float)(GetScreenWidth() / 2.3), 5 }, 50, 5, WHITE);
    DrawTextEx(ft, TextFormat("Bricks : %02i", nbBrick), Vector2{ 5, 5 }, 50, 5, WHITE);
    EndDrawing();
}

void End()
{
    CloseWindow();
}