#include "scenes/pauseScene.h"

#include "raylib.h"

#include "objects/button.h"
#include "objects/utils.h"
#include "scenes/menuScenes.h"

void initPauseButton()
{
	initButton(pauseGame, screenWidth - 250, screenHeight - 100);
}

void drawPause(bool& menuOn, bool& pauseOn)
{
	ClearBackground(BLACK);

	//DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

	//UpdateMusicStream(menuMusic);

	DrawText(TextFormat("Pause game"), (screenWidth / 2 - 150), (screenHeight / 2 - 100), 50, WHITE);

	DrawText(TextFormat("What Will You Do"), (screenWidth / 2 - 200), (screenHeight / 2 - sizeLetters), 50, WHITE);

	drawButton(resumeGame);
	drawResumeGameTitle();

	if (isButtonPressed(resumeGame))
	{
		//PlaySound(clickSfx);
		pauseOn = false;
	}

	drawBackToMenu(menuOn, pauseOn);
}