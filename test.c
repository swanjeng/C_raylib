#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char title[] = "Raylib Test";
    Color ballColor = {255, 0, 128, 255};

    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("move the ball with arrow keys", 10, 10, 30, DARKGRAY);
        DrawCircleV(ballPosition, 50, ballColor);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}