#include "raylib.h"

#include "objects/player.h"
#include "objects/utils.h"

int main()
{
    Player player;

    // Inicialización
    InitWindow(screenWidth, screenHeight, "Mi juego");

    initPlayer(player);

    // Loop
    while (!WindowShouldClose())
    {
        // Chequeo de Input

        updatePlayer(player);


        // Actualización

        // Dibujado
        BeginDrawing();
        ClearBackground(WHITE); // system("cls");

        drawPlayer(player);

        EndDrawing();
    }

    // Cierre
    CloseWindow();
}