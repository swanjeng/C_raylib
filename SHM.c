#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define FPS 60
#define MAX_DISPLACEMENT 200
#define PLOT_BASE (SCREEN_HEIGHT - 50 - MAX_DISPLACEMENT)

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
    Vector2 ballPosition = { SCREEN_WIDTH / 2 + MAX_DISPLACEMENT, 200 };
    float ballVelocity = 0, ballAcceleration = 0, force = 0;
    int x[700], y[700], ptr = 0;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title);
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
        force = -k * (ballPosition.x - SCREEN_WIDTH / 2);
        ballAcceleration = force / ballMass;
        ballVelocity += ballAcceleration * dt;
        ballPosition.x += ballVelocity * dt;

        int plotY = PLOT_BASE - (int)(ballPosition.x - SCREEN_WIDTH / 2);
        if (plotY < PLOT_BASE - MAX_DISPLACEMENT) {
            plotY = PLOT_BASE - MAX_DISPLACEMENT;
        } else if (plotY > PLOT_BASE + MAX_DISPLACEMENT) {
            plotY = PLOT_BASE + MAX_DISPLACEMENT;
        }

        if (ptr < 700) {
            x[ptr] = 50 + ptr * (SCREEN_WIDTH - 100) / 699;
            y[ptr] = plotY;
            ptr++;
        } else {
            for (int i = 0; i < 699; i++) {
                x[i] = x[i + 1] - 1;
                y[i] = y[i + 1];
            }
            x[699] = SCREEN_WIDTH - 50;
            y[699] = plotY;
        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawLine(0, 200, ballPosition.x - ballRadius, 200, lineColor);
        DrawCircleV(ballPosition, ballRadius, ballColor);
        for (int i = 0; i < ptr; i++) {
            DrawCircle(x[i], y[i], 2, BLUE);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}