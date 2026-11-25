#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 60
#define MAX_DISPLACEMENT 200

#ifdef RED
    #undef RED
#endif
#define RED (Color){255, 0, 0, 255}

#define DARK_GREEN (Color){0, 128, 0, 255}

#ifdef BLUE
    #undef BLUE
#endif
#define BLUE (Color){0, 0, 255, 255}

int main() {
    const char title[] = "簡諧運動模擬_使用Raylib";
    const float dt = 1.0 / FPS;
    const int ballRadius = 20, ballMass = 1, k = 5;
    Color ballColor = RED, lineColor = DARK_GREEN;
    Vector2 ballPosition = { SCREEN_WIDTH / 2 + MAX_DISPLACEMENT, 100 };
    float ballVelocity = 0, ballAcceleration = 0, force = 0;
    int x[400], y[400], ptr = 0;
    for (int i = 0 ; i < 400 ; i ++) {
        x[i] = -1;
        y[i] = 600 - i;
    }

    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title);
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
        force = -k * (ballPosition.x - SCREEN_WIDTH / 2);
        ballAcceleration = force / ballMass;
        ballVelocity += ballAcceleration * dt;
        ballPosition.x += ballVelocity * dt;

        if (ptr < 400) {
            x[ptr] = ballPosition.x;
            ptr++;
        } else {
            for (int i = 0; i < 399; i++) {
                x[i] = x[i + 1];
            }
            x[399] = ballPosition.x;
        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawLine(0, 100, ballPosition.x - ballRadius, 100, lineColor);
        DrawCircleV(ballPosition, ballRadius, ballColor);
        for (int i = 0; i < ptr; i++) {
            DrawCircle(x[i], y[i], 2, BLUE);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}