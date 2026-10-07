#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - image loading");
    SetTargetFPS(60);

    Image image = LoadImage("Resources/bliss.png");
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
        EndDrawing();
    }

    UnloadTexture(texture);
    return 0;
}