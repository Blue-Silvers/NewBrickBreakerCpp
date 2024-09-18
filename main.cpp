#include "raylib.h"
#include <iostream>
#include "TheBall.h"
#include "Paddle.h"


using namespace std;

    void Start();
    void Update();
    void Draw();
    void End();

TheBall theBall;
Paddle player;

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
    InitWindow(800, 800, "Pong Ping");
    SetTargetFPS(60);
    theBall.Start();
}

void Update() 
{
    theBall.Update();
    player.Update();
}

void Draw()
{
    BeginDrawing();

    ClearBackground(DARKBLUE);
    theBall.Draw();
    player.Draw();

    EndDrawing();
}

void End()
{
    CloseWindow();
}