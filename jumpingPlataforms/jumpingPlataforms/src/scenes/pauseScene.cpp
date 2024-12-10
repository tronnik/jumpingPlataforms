#include "scenes/pauseScene.h"

#include "raylib.h"

#include "objects/button.h"
#include "objects/utils.h"
#include "scenes/menuScenes.h"

static int seventy = 70;
static int hundred = 100;

void initPauseButton()
{
	initButton(pauseGame, screenWidth - 250, screenHeight - 100);
}

void drawPause(bool& menuOn, bool& pauseOn)
{
	ClearBackground(BLACK);

	DrawTexture(menuBackground, 0, 0, LIGHTGRAY);

	UpdateMusicStream(menuMusic);

	DrawTextEx(fontGame, "Pause game", { static_cast<float>(screenWidth / 2 - hundred), static_cast<float>(screenHeight / 2 - hundred) }, static_cast<float>(seventy), 0.0f, RED);

	DrawTextEx(fontGame, "What Will You Do?", { static_cast<float>(screenWidth / 2 - (hundred + seventy)), static_cast<float>(screenHeight / 2) }, static_cast<float>(seventy), 0.0f, RED);

	drawButton(resumeGame);
	drawResumeGameTitle();

	if (isButtonPressed(resumeGame))
	{
		PlaySound(clickSfx);
		pauseOn = false;
	}

	drawBackToMenu(menuOn, pauseOn);
}