#include "scenes/gameOverScene.h"

#include "raylib.h"

#include "objects/button.h"
#include "objects/utils.h"
#include "scenes/menuScenes.h"
#include "scenes/gameplayScenes.h"

namespace jumpingPlataform
{
	static int ten = 10;
	static int twenty = 20;
	static int forty = 40;
	static int fifty = 50;
	static int seventy = 70;
	static int hundred = 100;
	static int twoHundred = 200;

	void drawGameOverScene(bool& menuOn, bool& gameOver, int playerScore)
	{
		ClearBackground(BLACK);

		DrawTexture(menuBackground, 0, 0, LIGHTGRAY);

		UpdateMusicStream(menuMusic);

		DrawTextEx(fontGame, "Game Over", { static_cast<float>(screenWidth / 2 - hundred), static_cast<float>(screenHeight / 2 - hundred) }, static_cast<float>(seventy), 0.0f, PURPLE);

		DrawTextEx(fontGame, "Points: ", { static_cast<float>(screenWidth / 2 - 100), static_cast<float>(screenHeight / 2) }, static_cast<float>(seventy), 0.0f, PURPLE);

		DrawText(TextFormat("%01i", playerScore), (screenWidth / 2 + fifty), (screenHeight / 2 + ten), sizeLetters, PURPLE);

		DrawTextEx(fontGame, "What Will You Do?", { static_cast<float>(screenWidth / 2 - (hundred + seventy)), static_cast<float>(screenHeight / 2 + hundred) }, static_cast<float>(seventy), 0.0f, PURPLE);

		drawButton(playAgain);
		drawPlayAgainTitle();

		if (isButtonPressed(playAgain))
		{
			PlaySound(clickSfx);
			gameOver = false;
			resetGame();
		}

		drawBackToMenu(menuOn, gameOver);
	}
}
