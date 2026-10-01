#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char title[] = "拋體運動模擬_使用Raylib";
    const int ballRadius = 20;
    Color ballColor = {255, 0, 128, 255};

    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);

    Vector2 ballPosition = { 50, 50 };
    Vector2 ballVelocity = { 10, 0 };
    Vector2 gravity = {0, 0.5};

    while (!WindowShouldClose()) {
        ballVelocity.y += gravity.y;

        ballPosition.x += ballVelocity.x;
        ballPosition.y += ballVelocity.y;

        if (ballPosition.x < ballRadius) {
            ballPosition.x = ballRadius;
            ballVelocity.x *= -1;
        }
        if (ballPosition.x > screenWidth - ballRadius) {
            ballPosition.x = screenWidth - ballRadius;
            ballVelocity.x *= -1;
        }

        if (ballPosition.y < ballRadius) {
            ballPosition.y = ballRadius;
            ballVelocity.y *= -1;
        }
        if (ballPosition.y > screenHeight - ballRadius) {
            ballPosition.y = screenHeight - ballRadius;
            ballVelocity.y *= -0.9;
            ballVelocity.x *= 0.95;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(ballPosition, ballRadius, ballColor);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}