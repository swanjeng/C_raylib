#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define TITLE "猜數字遊戲 - 0 到 9"
#define BTN_NORMAL_COLOR SKYBLUE
#define BTN_HOVERED_COLOR BLUE
#define BTN_CLICKED_COLOR DARKBLUE

int main() {
    const char intToString[10][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    int btnPressed[10] = {}, pause = 0;
    int number = GetRandomValue(0, 9), guess = -1;
    char* text = "Guess between 0 and 9";
    
    Rectangle buttons[10];
    for (int i = 0 ; i < 10 ; i ++) buttons[i] = (Rectangle){150 + 50 * i, 250, 50, 50};
    Color buttonColor[10];
    for (int i = 0 ; i < 10 ; i ++)  buttonColor[i] = BTN_NORMAL_COLOR;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();
        for (int i = 0 ; i < 10 ; i ++) {
            if (CheckCollisionPointRec(mousePos, buttons[i])) {
                buttonColor[i] = BTN_HOVERED_COLOR;
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                    buttonColor[i] = BTN_CLICKED_COLOR;
                    btnPressed[i] = 1;
                } else {
                    btnPressed[i] = 0;
                }
            } else {
                buttonColor[i] = BTN_NORMAL_COLOR;
            }
        }

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
            DrawRectangleRec(buttons[i], buttonColor[i]);
            DrawText(intToString[i], buttons[i].x + buttons[i].width / 2, buttons[i].y + buttons[i].height / 2, 20, BLACK);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}