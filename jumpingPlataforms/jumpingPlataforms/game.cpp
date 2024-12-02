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
}

void updateGame()
{
	gameplayUpdate();
}

void drawGame()
{
	BeginDrawing();
	ClearBackground(WHITE); 

	gameplayDraw();

	EndDrawing();
}

void close()
{
	windowOpen = false;
}