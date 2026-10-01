#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define FPS 60
#define WHITE (Color){255, 255, 255, 255}
#define BLACK (Color){0, 0, 0, 255}
#define RED (Color){255, 0, 0, 255}

int main() {
    const char title[] = "簡諧運動模擬_使用Raylib";
    const float dt = 1.0 / FPS;
    const int ballRadius = 20, ballMass = 1, k = 5;
    Color ballColor = {255, 0, 128, 255}, lineColor = {0, 128, 0, 255};
    Vector2 ballPosition = { SCREEN_WIDTH / 2 + dx, SCREEN_HEIGHT / 2 };
    float ballVelocity = 0, ballAcceleration = 0, force = 0;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title);
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
        force = -k * (ballPosition.x - SCREEN_WIDTH / 2);
        ballAcceleration = force / ballMass;
        ballVelocity += ballAcceleration * dt;
        ballPosition.x += ballVelocity * dt;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawLine(0, SCREEN_HEIGHT / 2, ballPosition.x - ballRadius, SCREEN_HEIGHT / 2, lineColor);
        DrawCircleV(ballPosition, ballRadius, ballColor);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}