#include "game.h"

#include "raylib.h"

#include "objects/utils.h"
#include "objects/button.h"
#include "objects/player.h"
#include "scenes/menuScenes.h"
#include "scenes/pauseScene.h"
#include "scenes/gameOverScene.h"
#include "scenes/gameplayScenes.h"

namespace jumpingPlataform
{
	int screenHeight = 768;
	int screenHeightMin = 0;
	int screenWidth = 800;
	int screenWidthMin = 0;
	int sizeLetters = 50;
	float oneVolume = 0.1f;
	float threeVolume = 0.3f;

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
	Sound clickSfx;
	Texture2D menuBackground;
	Font fontGame;

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
			drawGameOverScene(menuOn, gameOver, player.score);
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
}