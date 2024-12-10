#include "scenes/gameOverScene.h"

#include "raylib.h"

#include "objects/button.h"
#include "objects/utils.h"
#include "scenes/menuScenes.h"
#include "scenes/gameplayScenes.h"

void drawGameOverScene(bool& menuOn, bool& gameOver)
{
	ClearBackground(BLACK);

	DrawTexture(menuBackground, 0, 0, LIGHTGRAY);

	UpdateMusicStream(menuMusic);

	DrawText(TextFormat("Game Over"), (screenWidth / 2 - 100 - 20), (screenHeight / 2 - 100), 50, WHITE);

	DrawText(TextFormat("What Will You Do?"), (screenWidth / 2 - 200), (screenHeight / 2 + 40), 50, WHITE);

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
