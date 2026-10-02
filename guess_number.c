#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char title[] = "猜數字遊戲_0 到 9";

    int btn0Pressed = 0;
    int btn1Pressed = 0;
    int btn2Pressed = 0;
    int btn3Pressed = 0;
    int btn4Pressed = 0;
    int btn5Pressed = 0;
    int btn6Pressed = 0;
    int btn7Pressed = 0;
    int btn8Pressed = 0;
    int btn9Pressed = 0;
    int number = GetRandomValue(0, 9);
    int guess = -1;
    int pause = 0;
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
            if (btn0Pressed) guess = 0;
            else if (btn1Pressed) guess = 1;
            else if (btn2Pressed) guess = 2;
            else if (btn3Pressed) guess = 3;
            else if (btn4Pressed) guess = 4;
            else if (btn5Pressed) guess = 5;
            else if (btn6Pressed) guess = 6;
            else if (btn7Pressed) guess = 7;
            else if (btn8Pressed) guess = 8;
            else if (btn9Pressed) guess = 9;
            
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
        ClearBackground(WHITE);
        DrawText(text, 100, 100, 30, BLACK);
        btn0Pressed = GuiButton((Rectangle) { 150, 250, 50, 50 }, "0");
        btn1Pressed = GuiButton((Rectangle) { 200, 250, 50, 50 }, "1");
        btn2Pressed = GuiButton((Rectangle) { 250, 250, 50, 50 }, "2");
        btn3Pressed = GuiButton((Rectangle) { 300, 250, 50, 50 }, "3");
        btn4Pressed = GuiButton((Rectangle) { 350, 250, 50, 50 }, "4");
        btn5Pressed = GuiButton((Rectangle) { 400, 250, 50, 50 }, "5");
        btn6Pressed = GuiButton((Rectangle) { 450, 250, 50, 50 }, "6");
        btn7Pressed = GuiButton((Rectangle) { 500, 250, 50, 50 }, "7");
        btn8Pressed = GuiButton((Rectangle) { 550, 250, 50, 50 }, "8");
        btn9Pressed = GuiButton((Rectangle) { 600, 250, 50, 50 }, "9");
        EndDrawing();
    }

    CloseWindow();
    return 0;
}