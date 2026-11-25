#include "raylib.h"
// Constants are defined here
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define TITLE "Raylib Template"
#define FPS 60
#define BACKGROUND_COLOR (Color){255, 255, 255, 255}

int main() {
    // Variables are declared here

    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
        // Variables are updated here
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        // Objects are drawn here
        EndDrawing();
    }

    CloseWindow();
    return 0;
}