#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char title[] = "碰撞模擬_使用Raylib";
    const int ballRadius = 20;
    float ball1Velocity = 5.0;
    float ball2Velocity = -5.0;
    float ball1Mass = 1.0;
    float ball2Mass = 10.0;
    Color ball1Color = {255, 0, 0, 255};
    Color ball2Color = {0, 0, 255, 255};
    Vector2 ball1Position = { 200, 255 };
    Vector2 ball2Position = { 600, 255 };
    
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        ball1Position.x += ball1Velocity;
        ball2Position.x += ball2Velocity;

        if (CheckCollisionCircles(ball1Position, ballRadius, ball2Position, ballRadius)) {
            float new_ball1Velocity = (ball1Velocity * (ball1Mass - ball2Mass) + 2 * ball2Mass * ball2Velocity) / (ball1Mass + ball2Mass);
            float new_ball2Velocity = (ball2Velocity * (ball2Mass - ball1Mass) + 2 * ball1Mass * ball1Velocity) / (ball2Mass + ball1Mass);
            ball1Velocity = new_ball1Velocity;
            ball2Velocity = new_ball2Velocity;
        }
        if (ball1Position.x < ballRadius) {
            ball1Position.x = ballRadius;
            ball1Velocity *= -1;
        }
        if (ball1Position.x > screenWidth - ballRadius) {
            ball1Position.x = screenWidth - ballRadius;
            ball1Velocity *= -1;
        }
        if (ball2Position.x < ballRadius) {
            ball2Position.x = ballRadius;
            ball2Velocity *= -1;
        }
        if (ball2Position.x > screenWidth - ballRadius) {
            ball2Position.x = screenWidth - ballRadius;
            ball2Velocity *= -1;
        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircleV(ball1Position, ballRadius, ball1Color);
        DrawCircleV(ball2Position, ballRadius, ball2Color);
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}