#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define FPS 60
#define MAX_DISPLACEMENT 200

#ifdef RED
    #undef RED
#endif
#define RED (Color){255, 0, 0, 255}

#define DARK_GREEN (Color){0, 128, 0, 255}

int main() {
    const char title[] = "簡諧運動模擬_使用Raylib";
    const float dt = 1.0 / FPS;
    const int ballRadius = 20, ballMass = 1, k = 5;
    Color ballColor = RED, lineColor = DARK_GREEN;
    Vector2 ballPosition = { SCREEN_WIDTH / 2 + MAX_DISPLACEMENT, SCREEN_HEIGHT / 2 };
    float ballVelocity = 0, ballAcceleration = 0, force = 0;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title);
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
        force = -k * (ballPosition.x - SCREEN_WIDTH / 2);
        ballAcceleration = force / ballMass;
        ballVelocity += ballAcceleration * dt;
        ballPosition.x += ballVelocity * dt;

        BeginDrawing();
        ClearBackground(WHITE);
        DrawLine(0, SCREEN_HEIGHT / 2, ballPosition.x - ballRadius, SCREEN_HEIGHT / 2, lineColor);
        DrawCircleV(ballPosition, ballRadius, ballColor);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}