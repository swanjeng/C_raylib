#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define TITLE "按鈕測試 - Raylib"

int main() {
    Rectangle plusButton = {100, 300, 200, 100};
    Rectangle minusButton = {500, 300, 200, 100};
    Color plusColor, minusColor;
    Vector2 mousePos;
    int counter = 0;
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        mousePos = GetMousePosition();
        if (CheckCollisionPointRec(mousePos, plusButton)) {
            plusColor = BLUE;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                plusColor = DARKBLUE;
                counter ++;
            }
        } else {
            plusColor = SKYBLUE;
        }
        if (CheckCollisionPointRec(mousePos, minusButton)) {
            minusColor = BLUE;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                minusColor = DARKBLUE;
                counter --;
            }
        } else {
            minusColor = SKYBLUE;
        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawText(TextFormat("%d", counter), 300, 100, 50, BLACK);
        DrawRectangleRec(plusButton, plusColor);
        DrawText("+", plusButton.x + plusButton.width / 2, plusButton.y + plusButton.height / 2, 50, RAYWHITE);
        DrawRectangleRec(minusButton, minusColor);
        DrawText("-", minusButton.x + minusButton.width / 2, minusButton.y + minusButton.height / 2, 50, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}