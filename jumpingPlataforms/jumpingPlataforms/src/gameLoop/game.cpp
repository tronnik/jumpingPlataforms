#include "game.h"

#include "raylib.h"

#include "objects/utils.h"
#include "scenes/gameplayScenes.h"
#include "scenes/menuScenes.h"
#include "objects/button.h"

int screenHeight = 768;
int screenHeightMin = 0;
int screenWidth = 800;
int screenWidthMin = 0;
int sizeLetters = 30;

bool menuOn = true;
bool controlsOn = false;
bool creditsOn = false;
bool creditsOn2 = false;
bool exitOn = false;
bool gameOver = false;
bool pauseOn = false;
bool windowOpen = true;

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
	//if (!menuOn && !gameOver && !creditsOn && !creditsOn2 && !controlsOn && !pauseOn)
	if (!menuOn)
	{
		gameplayUpdate();
	}


}

void drawGame()
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawText(TextFormat(" 0"), (screenWidth / 2), screenHeightMin, 30, RED);

	DrawText(TextFormat(" 768"), (screenWidth / 2), screenHeight - 50, 30, RED);

	DrawText(TextFormat(" 0"), screenWidthMin, screenHeight / 2, 30, RED);

	DrawText(TextFormat(" 768"), screenWidth - 80, screenHeight / 2, 30, RED);

	if (menuOn)
	{
		drawMenu(menuOn, controlsOn, creditsOn);
	}
	else if (controlsOn)
	{
		drawConstrols(menuOn, controlsOn);
	}
	else if (creditsOn)
	{
		drawCredits(menuOn, creditsOn, creditsOn2);
	}
	else if (creditsOn2)
	{
		drawSecondCredits(menuOn, creditsOn, creditsOn2);
	}
	else
	{
		gameplayDraw();
	}
	
	//gameplayDraw();

	EndDrawing();
}

void close()
{
	windowOpen = false;
}