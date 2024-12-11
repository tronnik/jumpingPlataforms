#include "scenes/gameplayPaused.h"

#include "raylib.h"

#include "objects/utils.h"
#include "gameLoop/game.h"
#include "scenes/gameplayScenes.h"

namespace jumpingPlataform
{
	static int fifty = 50;
	static int oneHundredFifty = 150;
	static int twoHundred = 200;

	 float gameInterval = 5.0f;

	void updateGameplyaPaused(bool& gameplayPaused)
	{
		ClearBackground(BLANK);

		PlayMusicStream(gameplayMusic);
		UpdateMusicStream(gameplayMusic);

		gameInterval -= GetFrameTime();

		if (gameInterval <= 0.0f)
		{
			gameplayPaused = false;
			gameInterval = 5.0f; 
		}
	}

	void drawGameplayPaused(bool& menuOn, bool& pauseOn)
	{
		gameplayDraw(menuOn, pauseOn);

		DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.5f));

		DrawTextEx(fontGame, "Astronaut Survive will begin in:", { static_cast<float>(screenWidth / 2 - twoHundred), static_cast<float>(oneHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, PURPLE);

		DrawText(TextFormat("%01i", static_cast<int>(gameInterval)), (screenWidth / 2 ), (screenHeight / 2 - fifty), sizeLetters, PURPLE);

	}
}
