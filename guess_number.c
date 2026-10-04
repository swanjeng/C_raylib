#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
    const int screenWidth = 800, screenHeight = 450;
    const char title[] = "猜數字遊戲 - 0 到 9", intToString[10][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    int btnPressed[10] = {}, pause = 0;
    int number = GetRandomValue(0, 9), guess = -1;
    char* text;

    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 50);

    while (!WindowShouldClose()) {
        if (pause && (IsKeyDown('r') || IsKeyDown('R'))) {
            pause = 0;
            number = GetRandomValue(0, 9);
            guess = -1;
        }
        
        if (!pause) {
            for (int i = 0 ; i <= 9 ; i ++) {
                if (btnPressed[i]) {
                    guess = i;
                    break;
                }
            }
            
            if (guess != -1) {
                if (guess > number) text = "Too high";
                else if (guess < number) text = "Too low";
                else {
                    text = "Correct! Press R to play again";
                    pause = 1;
                }
            } else text = "Guess between 0 and 9";
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(text, 100, 100, 30, BLACK);
        for (int i = 0 ; i <= 9 ; i ++) {
            btnPressed[i] = GuiButton((Rectangle) {150 + 50 * i, 250, 50, 50}, intToString[i]);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}