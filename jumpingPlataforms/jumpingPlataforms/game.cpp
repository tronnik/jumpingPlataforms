#include "game.h"

#include "raylib.h"

#include "objects/utils.h"
#include "scenes/gameplayScenes.h"

bool windowOpen = true;

int screenHeight = 768;
int screenHeightMin = 0;
int screenWidth = 800;
int screenWidthMin = 0;

static void initializationGame();
static void updateGame();
static void drawGame();

void run()
{
	initializationGame();

	while (!WindowShouldClose() && windowOpen)
	{
		updateGame();
	
		drawGame();
	}

	close();

	CloseWindow();
}

void initializationGame()
{
	InitWindow(screenWidth, screenHeight, "Mi juego");

	gameplayInit();

	loadGameplayTextures();
}

void updateGame()
{
	gameplayUpdate();
}

void drawGame()
{
	BeginDrawing();
	ClearBackground(BLACK); 

	DrawText(TextFormat(" 0"), (screenWidth / 2), screenHeightMin, 30, RED);

	DrawText(TextFormat(" 768"), (screenWidth / 2), screenHeight - 50, 30, RED);

	DrawText(TextFormat(" 0"), screenWidthMin, screenHeight / 2, 30, RED);

	DrawText(TextFormat(" 768"), screenWidth - 80, screenHeight / 2, 30, RED);

	gameplayDraw();

	EndDrawing();
}

void close()
{
	windowOpen = false;
}