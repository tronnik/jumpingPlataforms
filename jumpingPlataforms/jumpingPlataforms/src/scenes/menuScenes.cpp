#include "scenes/menuScenes.h"

#include "raylib.h"

#include "objects/utils.h"
#include "gameLoop/game.h"
#include "objects/button.h"
#include "objects/player.h"
#include "scenes/gameplayScenes.h"

Button ItchButton;
Button backgroundButton;
Button jumpSfx;
Button raylibButton;
Button loseSfx;

Button MenuMusicButton;
Button gameplayMusicButton;
Button clickSfxButton;
Button gameOverSfx;
Button pointsSfx;
Button spriteButton;
Button keysButton;

static void drawPageButton(bool& creditsOn, bool& creditsOn2);

static int ten = 10;
static int thirty = 30;
static int twenty = 20;
static int fifty = 50;
static int hundred = 100;
static int oneHundredFifty = 150;
static int twoHundred = 200;
static int twoHundredFifty = 250;
static int threeHundredFifty = 350;
static int fourHundredFifty = 450;
static int fiveHundred = 500;
static int sevenHundred = 700;

static Texture2D aKey;
static Texture2D dKey;
static Texture2D arrowLeft;
static Texture2D arrowRight;

void initMenu()
{
	initButton(button, (screenWidth / 2 - hundred), threeHundredFifty);

	initButton(controls, (screenWidth / 2 - hundred), (fiveHundred + fifty));

	initButton(credits, (screenWidth / 2 - hundred), fourHundredFifty);

	initButton(exitGame, (screenWidth / 2 - hundred), (fiveHundred + oneHundredFifty));

	initButton(backToMenu, (screenWidth / 2 + fifty), sevenHundred);

	initButton(resumeGame, (screenWidth / 2 - twoHundred), sevenHundred);

	initButton(playAgain, (screenWidth / 2 - twoHundred), sevenHundred);

	initButton(ItchButton, (screenWidth / 2 + fifty), oneHundredFifty);

	initButton(backgroundButton, (screenWidth / 2 + fifty), twoHundredFifty);

	initButton(raylibButton, (screenWidth / 2 + fifty), threeHundredFifty);

	initButton(jumpSfx, (screenWidth / 2 + fifty), fourHundredFifty);

	initButton(loseSfx, (screenWidth / 2 + fifty), fiveHundred + fifty);

	initButton(MenuMusicButton, (screenWidth / 2 + fifty), hundred);

	initButton(gameplayMusicButton, (screenWidth / 2 + fifty), (oneHundredFifty + thirty));

	initButton(clickSfxButton, (screenWidth / 2 + fifty), (twoHundredFifty + ten));

	initButton(gameOverSfx, (screenWidth / 2 + fifty), (threeHundredFifty - ten));

	initButton(pointsSfx, (screenWidth / 2 + fifty), (fourHundredFifty - thirty));

	initButton(spriteButton, (screenWidth / 2 + fifty), fiveHundred);

	initButton(keysButton, (screenWidth / 2 + fifty), (fiveHundred + hundred - twenty));

	initPageButton(page1, (screenWidth / 2 - oneHundredFifty), sevenHundred);

	initPageButton(page2, (screenWidth / 2 - fifty), sevenHundred);
}

void loadMenu()
{
	menuMusic = LoadMusicStream("res/menuMusic.mp3");
	menuBackground = LoadTexture("res/menuBackground.png");
	clickSfx = LoadSound("res/clickSfx.mp3");
	fontGame = LoadFont("res/Radioz.ttf");
	aKey = LoadTexture("res/aKey.png");
	dKey = LoadTexture("res/dKey.png");
	arrowLeft = LoadTexture("res/arrowLeft.png");
	arrowRight = LoadTexture("res/arrowRight.png");
}

void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn)
{
	ClearBackground(BLACK);

	SetMusicVolume(menuMusic, oneVolume);
	
	PlayMusicStream(menuMusic);
	UpdateMusicStream(menuMusic);

	SetSoundVolume(clickSfx, threeVolume);
	
	DrawTexture(menuBackground, 0, 0, LIGHTGRAY);


	DrawTextEx(fontGame, "Astronaut Survive", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(oneHundredFifty) }, static_cast<float>(hundred), 0.0f, VIOLET);

	drawButton(button);
	drawButton(controls);
	drawButton(credits);
	drawButton(exitGame);

	drawPlayTitle();
	drawControlTitle();
	drawCreditsTitle();
	drawExitTitle();

	if (isButtonPressed(button))
	{
		PlaySound(clickSfx);

		menuOn = false;

		resetGame();
	}

	if (isButtonPressed(controls))
	{
		PlaySound(clickSfx);
		controlsOn = true;
		menuOn = false;
	}

	if (isButtonPressed(credits))
	{
		PlaySound(clickSfx);
		creditsOn = true;
		menuOn = false;
	}

	if (isButtonPressed(exitGame))
	{
		PlaySound(clickSfx);
		StopMusicStream(menuMusic);

		close();
	}

	if (isButtonPressed(backToMenu))
	{
		PlaySound(clickSfx);
		menuOn = true;
		creditsOn = false;
		controlsOn = false;
	}
}

void drawConstrols(bool& menuOn, bool& controlsOn)
{
	float scale = 3.0f;

	ClearBackground(BLACK);

	DrawTexture(menuBackground, 0, 0, LIGHTGRAY);

	UpdateMusicStream(menuMusic);

	DrawTextEx(fontGame, "CONTROLS", { static_cast<float>(screenWidth / 2 - fifty - twenty), static_cast<float>(hundred) }, static_cast<float>(fifty), 0.0f, VIOLET);

	DrawTextEx(fontGame, "Move left:", { static_cast<float>(screenWidth / 2) - (twoHundred + twenty), static_cast<float>(twoHundredFifty) }, static_cast<float>(fifty), 0.0f, RED);

	DrawTextureEx(arrowLeft, { static_cast<float> (screenWidth / 2 + hundred), static_cast<float>(twoHundredFifty) }, 0.0f, scale, WHITE);
	DrawTextureEx(aKey, { static_cast<float> (screenWidth / 2 + oneHundredFifty), static_cast<float>(twoHundredFifty) }, 0.0f, scale, WHITE);

	DrawTextEx(fontGame, "Move Right:", { static_cast<float>((screenWidth / 2) - (twoHundred + 20)), static_cast<float>(threeHundredFifty) }, static_cast<float>(fifty), 0.0f, RED);

	DrawTextureEx(arrowRight, { static_cast<float> (screenWidth / 2 + hundred), static_cast<float>(threeHundredFifty) }, 0.0f, scale, WHITE);
	DrawTextureEx(dKey, { static_cast<float> (screenWidth / 2 + oneHundredFifty), static_cast<float>(threeHundredFifty) }, 0.0f, scale, WHITE);

	drawBackToMenu(menuOn, controlsOn);

}

void drawCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
{
	ClearBackground(BLACK);

	DrawTexture(menuBackground, 0, 0, LIGHTGRAY);

	UpdateMusicStream(menuMusic);

	DrawTextEx(fontGame, "CREDITS", { static_cast<float>(screenWidth / 2 - fifty - twenty), static_cast<float>(fifty) }, static_cast<float>(sizeLetters), 0.0f, VIOLET);

	DrawTextEx(fontGame, "Developer", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(oneHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(ItchButton);
	DrawTextEx(fontGame, "Valentin Villar", { static_cast<float>(screenWidth / 2 + fifty + ten), static_cast<float>(oneHundredFifty + ten) }, static_cast<float>(sizeLetters - ten), 0.0f, RED);
	if (isButtonPressed(ItchButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://valentin-villar.itch.io/");
	}

	DrawTextEx(fontGame, "Backgrounds By", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(twoHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(backgroundButton);
	DrawTextEx(fontGame, "Leonardo.ia", { static_cast<float>(screenWidth / 2 + fifty + ten), static_cast<float>(twoHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	if (isButtonPressed(backgroundButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://app.leonardo.ai/image-generation");
	}

	DrawTextEx(fontGame, "Library", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(threeHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(raylibButton);
	DrawTextEx(fontGame, "Raylib", { static_cast<float>(screenWidth / 2 + hundred + ten), static_cast<float>(threeHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	if (isButtonPressed(raylibButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://www.raylib.com/index.html");
	}

	DrawTextEx(fontGame, "Jump sfx", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(fourHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(jumpSfx);
	DrawTextEx(fontGame, "Elevenslab", { static_cast<float>(screenWidth / 2 + hundred - 30), static_cast<float>(fourHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	if (isButtonPressed(jumpSfx))
	{
		PlaySound(clickSfx);
		OpenURL("https://elevenlabs.io/app/sound-effects/history");
	}

	DrawTextEx(fontGame, "Lose sfx", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(fiveHundred + fifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(loseSfx);
	DrawTextEx(fontGame, "Freesound", { static_cast<float>(screenWidth / 2 + hundred - 30), static_cast<float>(fiveHundred + fifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	if (isButtonPressed(loseSfx))
	{
		PlaySound(clickSfx);
		OpenURL("https://freesound.org/people/suntemple/sounds/253174/");
	}

	drawPageButton(creditsOn, creditsOn2);

	drawBackToMenu(menuOn, creditsOn);

}

void drawSecondCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
{
	ClearBackground(BLACK);

	DrawTexture(menuBackground, 0, 0, LIGHTGRAY);

	UpdateMusicStream(menuMusic);

	DrawTextEx(fontGame, "CREDITS", { static_cast<float>(screenWidth / 2 - fifty - twenty), static_cast<float>(fifty - ten) }, static_cast<float>(sizeLetters), 0.0f, VIOLET);

	DrawTextEx(fontGame, "Menu Music", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(hundred) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(MenuMusicButton);
	DrawTextEx(fontGame, "Tronik", { static_cast<float>(screenWidth / 2 + hundred), static_cast<float>(hundred) }, static_cast<float>(sizeLetters), 0.0f, RED);
	if (isButtonPressed(MenuMusicButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://suno.com/song/1f50ed34-cad9-45c1-a778-1daaa4bc162e");
	}

	DrawTextEx(fontGame, "Gameplay Music", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(twoHundred - twenty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(gameplayMusicButton);	
	DrawTextEx(fontGame, "Tronik", { static_cast<float>(screenWidth / 2 + hundred), static_cast<float>(twoHundred - twenty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	if (isButtonPressed(gameplayMusicButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://suno.com/song/8bd8538e-799e-4c38-b2b6-80c1e0cb0327");
	}

	DrawTextEx(fontGame, "Click SFX", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(twoHundredFifty + ten) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(clickSfxButton);
	DrawTextEx(fontGame, "Pixaby", { static_cast<float>(screenWidth / 2 + hundred), static_cast<float>(twoHundredFifty + ten) }, static_cast<float>(sizeLetters), 0.0f, RED);
	if (isButtonPressed(clickSfxButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://pixabay.com/sound-effects/click-234708/");
	}

	DrawTextEx(fontGame, "Game Over sfx", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(threeHundredFifty - ten) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(gameOverSfx);
	DrawTextEx(fontGame, "Freesound", { static_cast<float>(screenWidth / 2 + hundred - thirty), static_cast<float>(threeHundredFifty - ten) }, static_cast<float>(sizeLetters), 0.0f, RED);
	if (isButtonPressed(gameOverSfx))
	{
		PlaySound(clickSfx);
		OpenURL("https://freesound.org/people/MATRIXXX_/sounds/365766/");
	}

	DrawTextEx(fontGame, "Points sfx", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(fourHundredFifty - thirty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(pointsSfx);
	DrawTextEx(fontGame, "Freesound", { static_cast<float>(screenWidth / 2 + hundred - thirty), static_cast<float>(fourHundredFifty - thirty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	if (isButtonPressed(pointsSfx))
	{
		PlaySound(clickSfx);
		OpenURL("https://freesound.org/people/Joao_Janz/sounds/482653/");
	}

	DrawTextEx(fontGame, "Sprite Width", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(fiveHundred) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(spriteButton);
	DrawTextEx(fontGame, "Piskel", { static_cast<float>(screenWidth / 2 + hundred), static_cast<float>(fiveHundred) }, static_cast<float>(sizeLetters), 0.0f, RED);
	if (isButtonPressed(spriteButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://www.piskelapp.com/");
	}

	DrawTextEx(fontGame, "Keys By", { static_cast<float>(screenWidth / 2 - twoHundredFifty), static_cast<float>(fiveHundred + hundred - twenty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	drawButton(keysButton);
	DrawTextEx(fontGame, "Dream Mix", { static_cast<float>(screenWidth / 2 + fifty + twenty), static_cast<float>(fiveHundred + hundred -twenty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	if (isButtonPressed(keysButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://dreammix.itch.io/keyboard-keys-for-ui");
	}

	drawPageButton(creditsOn, creditsOn2);

	drawBackToMenu(menuOn, creditsOn2);
}

void drawBackToMenu(bool& boolTrue, bool& boolFalse)
{
	ClearBackground(BLACK);

	drawButton(backToMenu);

	drawBackToMenuTitle();

	if (isButtonPressed(backToMenu))
	{
		PlaySound(clickSfx);
		boolTrue = true;
		boolFalse = false;
	}
}

void drawPageButton(bool& creditsOn, bool& creditsOn2)
{
	ClearBackground(BLACK);

	drawButton(page1);
	drawPage1Title();

	if (isButtonPressed(page1))
	{
		PlaySound(clickSfx);
		creditsOn = true;
		creditsOn2 = false;
	}

	drawButton(page2);
	drawPage2Title();

	if (isButtonPressed(page2))
	{
		PlaySound(clickSfx);
		creditsOn = false;
		creditsOn2 = true;
	}
}

void unloadMenu()
{
	UnloadTexture(menuBackground);
	UnloadMusicStream(menuMusic);
	UnloadSound(clickSfx);
}


