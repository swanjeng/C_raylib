#include "raylib.h"
#include <math.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define TITLE "拋體與自由落體 - Raylib"
#define BALL_RADIUS 20
#define DISTANCE 750
#define BALL_HEIGHT 400
#define BALL1_VEL_MAG 5

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(60);

    Vector2 ball1Position = {SCREEN_WIDTH / 2 - DISTANCE / 2, SCREEN_HEIGHT - BALL_RADIUS};
    Vector2 ball2Position = {SCREEN_WIDTH / 2 + DISTANCE / 2, SCREEN_HEIGHT - BALL_HEIGHT};
    double theta = atan((ball1Position.y - ball2Position.y) * 1.0 / (ball2Position.x - ball1Position.x));
    Vector2 ball1Velocity = {BALL1_VEL_MAG * cos(theta), -BALL1_VEL_MAG * sin(theta)};
    Vector2 ball2Velocity = {0, 0};
    Vector2 gravity = {0, 0.1};

    while (!WindowShouldClose()) {
        ball1Velocity.y += gravity.y;
        ball2Velocity.y += gravity.y;
        
        ball1Position.x += ball1Velocity.x;
        ball1Position.y += ball1Velocity.y;
        
        ball2Position.y += ball2Velocity.y;

        if (ball1Position.x > ball2Position.x) {
            ball1Position.x = ball2Position.x;
        }
        if (ball1Position.y > SCREEN_HEIGHT - BALL_RADIUS) {
            ball1Position.y = SCREEN_HEIGHT - BALL_RADIUS;
        }
        if (ball2Position.y > SCREEN_HEIGHT - BALL_RADIUS) {
            ball2Position.y = SCREEN_HEIGHT - BALL_RADIUS;
        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircleV(ball1Position, BALL_RADIUS, (Color) {255, 0, 0, 255});
        DrawCircleV(ball2Position, BALL_RADIUS, (Color) {0, 0, 255, 255});
        EndDrawing();
    }

    CloseWindow();
    return 0;
}