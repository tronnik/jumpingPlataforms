#include "game.h"

#include "raylib.h"

#include "objects/utils.h"
#include "objects/button.h"
#include "scenes/menuScenes.h"
#include "scenes/pauseScene.h"
#include "scenes/gameOverScene.h"
#include "scenes/gameplayScenes.h"

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

Music menuMusic;
Music gameplayMusic;

static void initializationGame();
static void updateGame();
static void drawGame();
static void UnloadGameTextureAndMusic();

void run()
{
	initializationGame();

	while (!WindowShouldClose() && windowOpen)
	{
		updateGame();

		drawGame();
	}

	close();

	UnloadGameTextureAndMusic();

	CloseWindow();
}

void initializationGame()
{
	InitWindow(screenWidth, screenHeight, "Mi juego");

	InitAudioDevice();

	gameplayInit();
	initMenu();

	loadGameplayTextures();
	loadMenu();
}

void updateGame()
{
	if (!menuOn && !gameOver && !creditsOn && !creditsOn2 && !controlsOn && !pauseOn)
		gameplayUpdate(gameOver);
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
	else if (gameOver)
	{
		drawGameOverScene(menuOn, gameOver);
	}
	else if (pauseOn)
	{
		drawPause(menuOn, pauseOn);
	}
	else
	{
		gameplayDraw(menuOn, pauseOn);
	}
	
	EndDrawing();
}

void UnloadGameTextureAndMusic()
{
	unloadMenu();
	unloadGameplay();
}

void close()
{
	windowOpen = false;
}