#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define TITLE "按鈕測試 - Raylib"

int main() {
    // Define variables used in the program
    Rectangle plusButton = {100, 300, 200, 100};
    Rectangle minusButton = {500, 300, 200, 100};
    Color plusColor, minusColor;
    Vector2 mousePos;
    int counter = 0, plusPressed = 0, minusPressed = 0;
    
    // Initialize window and OpenGL context
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(60);

    // Main loop
    while (!WindowShouldClose()) {
        // Process mouse input and update button states
        mousePos = GetMousePosition();
        if (CheckCollisionPointRec(mousePos, plusButton)) {
            plusColor = BLUE;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                if (!plusPressed) {
                    counter++;
                }
                plusPressed = 1;
                plusColor = DARKBLUE;
            }
        } else {
            plusColor = SKYBLUE;
        }
        if (CheckCollisionPointRec(mousePos, minusButton)) {
            minusColor = BLUE;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                if (!minusPressed) {
                    counter--;
                }
                minusPressed = 1;
                minusColor = DARKBLUE;
            }
        } else {
            minusColor = SKYBLUE;
        }
        if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            plusPressed = 0;
            minusPressed = 0;
        }

        // Draw the UI elements on the screen
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText(TextFormat("%d", counter), 300, 100, 50, BLACK);
        DrawRectangleRec(plusButton, plusColor);
        DrawText("+", plusButton.x + plusButton.width / 2, plusButton.y + plusButton.height / 2, 50, RAYWHITE);
        DrawRectangleRec(minusButton, minusColor);
        DrawText("-", minusButton.x + minusButton.width / 2, minusButton.y + minusButton.height / 2, 50, RAYWHITE);
        EndDrawing();
    }

    // Close the window and clean up resources
    CloseWindow();
    return 0;
}