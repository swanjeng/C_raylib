#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char title[] = "按鈕";
    
    int btnPlusPressed = 0;
    int btnMinusPressed = 0;
    int counter = 0;
    
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);
    Font customFont = LoadFontEx("./Resources/Iansui-Regular.ttf", 32, NULL, 0);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 70);
    GuiSetFont(customFont);

    while (!WindowShouldClose()) {
        if (btnPlusPressed) counter ++;
        if (btnMinusPressed) counter --;

        char text[256];
        int counter1 = counter, p = 0;
        while (counter1 > 0) {
            text[p] = counter1 % 10 + '0';
            counter1 /= 10;
            p ++;
            if (p >= 255) break;
        }
        for (int i = 0 ; i < p / 2 ; i ++) {
            char tmp = text[i];
            text[i] = text[p - i - 1];
            text[p - i - 1] = tmp;
        }
        if (p == 0) {
            text[0] = '0';
            p = 1;
        }
        text[p] = '\0';

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextEx(customFont, text, (Vector2){300, 100}, 50, 2, BLACK);
        btnPlusPressed = GuiButton((Rectangle) { 500, 250, 200, 100 }, "+");
        btnMinusPressed = GuiButton((Rectangle) { 100, 250, 200, 100 }, "-");
        EndDrawing();
    }

    UnloadFont(customFont);
    CloseWindow();
    return 0;
}