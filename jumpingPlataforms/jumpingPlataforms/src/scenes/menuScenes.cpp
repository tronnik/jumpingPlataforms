#include "scenes/menuScenes.h"

#include "raylib.h"

#include "objects/utils.h"
#include "gameLoop/game.h"
#include "objects/button.h"
#include "objects/player.h"
#include "scenes/gameplayScenes.h"

Button ItchButton;
Button backgroundButton;
Button spaceShipButton;
Button bulletsButton;
Button raylibButton;

Button MenuMusicButton;
Button gameplayMusicButton;
Button clickSfxButton;
Button explosionSfxButton;
Button loseSfxButton;
Button boostSfxButton;
Button shootSfxButton;


static void drawPageButton(bool& creditsOn, bool& creditsOn2);

static int hundred = 100;
static int fifty = 50;
static int oneHundredFifty = 150;
static int twoHundred = 200;
static int twoHundredFifty = 250;
static int threeHundredFifty = 350;
static int fourHundredFifty = 450;
static int fiveHundred = 500;

static int sevenHundred = 700;

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

	initButton(spaceShipButton, (screenWidth / 2 + fifty), threeHundredFifty);

	initButton(bulletsButton, (screenWidth / 2 + fifty), fourHundredFifty);

	initButton(raylibButton, (screenWidth / 2 + fifty), (fiveHundred + fifty));

	initButton(MenuMusicButton, (screenWidth / 2 + fifty), hundred);

	initButton(gameplayMusicButton, (screenWidth / 2 + fifty), (oneHundredFifty + 30));

	initButton(clickSfxButton, (screenWidth / 2 + fifty), (twoHundredFifty + 10));

	initButton(explosionSfxButton, (screenWidth / 2 + fifty), (threeHundredFifty - 10));

	initButton(loseSfxButton, (screenWidth / 2 + fifty), (fourHundredFifty - 30));

	initButton(boostSfxButton, (screenWidth / 2 + fifty), fiveHundred);

	initButton(shootSfxButton, (screenWidth / 2 + fifty), (fiveHundred + 80));

	initPageButton(page1, (screenWidth / 2 - oneHundredFifty), sevenHundred);

	initPageButton(page2, (screenWidth / 2 - fifty), sevenHundred);
}

void loadMenu()
{
	menuMusic = LoadMusicStream("res/menuMusic.mp3");
	menuBackground = LoadTexture("res/menuBackground.png");
	clickSfx = LoadSound("res/clickSfx.mp3");
}

void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn)
{
	ClearBackground(BLACK);

	SetMusicVolume(menuMusic, 0.5f);
	
	PlayMusicStream(menuMusic);
	UpdateMusicStream(menuMusic);

	SetSoundVolume(clickSfx, 0.3f);
	
	DrawTexture(menuBackground, 0, 0, LIGHTGRAY);

	DrawText(TextFormat("Astronaut Survive"), (screenWidth / 2 - twoHundredFifty), oneHundredFifty, fifty, RED);

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
	ClearBackground(BLACK);

	DrawTexture(menuBackground, 0, 0, LIGHTGRAY);

	UpdateMusicStream(menuMusic);

	DrawText("CONTROLS", (screenWidth / 2 - hundred), hundred, sizeLetters + 10, WHITE);

	DrawText("Left Click: ", (screenWidth / 2) - (twoHundred + 20), twoHundredFifty, sizeLetters, WHITE);

	DrawText("Shoot", (screenWidth / 2 + hundred), twoHundredFifty, sizeLetters, WHITE);

	DrawText("Right Click: ", (screenWidth / 2) - (twoHundred + 20), threeHundredFifty, sizeLetters, WHITE);

	DrawText("Move", (screenWidth / 2 + hundred), threeHundredFifty, sizeLetters, WHITE);

	drawBackToMenu(menuOn, controlsOn);

}

void drawCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
{
	ClearBackground(BLACK);

	DrawTexture(menuBackground, 0, 0, LIGHTGRAY);

	UpdateMusicStream(menuMusic);

	DrawText(TextFormat("CREDITS"), (screenWidth / 2 - fifty), fifty, sizeLetters, WHITE);

	DrawText("Developer: ", (screenWidth / 2 - twoHundredFifty), oneHundredFifty, sizeLetters, WHITE);

	drawButton(ItchButton);
	DrawText("Valentin Villar", (screenWidth / 2 + fifty + 10), oneHundredFifty + 10, sizeLetters - 5, RED);
	if (isButtonPressed(ItchButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://valentin-villar.itch.io/");
	}

	DrawText("Background By: ", (screenWidth / 2 - twoHundredFifty), twoHundredFifty, sizeLetters, WHITE);
	drawButton(backgroundButton);
	DrawText("YO", (screenWidth / 2 + hundred - 10), (twoHundredFifty + 10), sizeLetters, RED);
	if (isButtonPressed(backgroundButton))
	{
		PlaySound(clickSfx);
		//OpenURL("https://ansimuz.itch.io/space-background");
	}


	DrawText("vacio: ", (screenWidth / 2 - twoHundredFifty), threeHundredFifty, sizeLetters, WHITE);
	drawButton(spaceShipButton);
	DrawText("vacio", (screenWidth / 2 + hundred - 30), (threeHundredFifty + 10), (sizeLetters - 5), RED);
	if (isButtonPressed(spaceShipButton))
	{
		PlaySound(clickSfx);
		//OpenURL("https://pixel-by-pixel.itch.io/alcwilliam-space-ship-pack");
	}

	DrawText("vacio By: ", (screenWidth / 2 - twoHundredFifty), fourHundredFifty, sizeLetters, WHITE);
	drawButton(bulletsButton);
	DrawText("vacio", (screenWidth / 2 + hundred), (fourHundredFifty + 10), sizeLetters, RED);
	if (isButtonPressed(bulletsButton))
	{
		PlaySound(clickSfx);
		//OpenURL("https://ho88it.itch.io/2-d-projectile-sprites-wild-west-character-pack");
	}

	DrawText("Library: ", (screenWidth / 2 - twoHundredFifty), (fiveHundred + fifty), sizeLetters, WHITE);

	drawButton(raylibButton);
	DrawText("Raylib", (screenWidth / 2 + hundred - 10), (fiveHundred + 60), sizeLetters, RED);
	if (isButtonPressed(raylibButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://www.raylib.com/index.html");
	}

	drawPageButton(creditsOn, creditsOn2);

	drawBackToMenu(menuOn, creditsOn);

}

void drawSecondCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
{
	ClearBackground(BLACK);

	DrawTexture(menuBackground, 0, 0, LIGHTGRAY);

	UpdateMusicStream(menuMusic);

	DrawText(TextFormat("CREDITS"), (screenWidth / 2 - hundred - 40), fifty, sizeLetters, WHITE);

	DrawText("Menu Music: ", (screenWidth / 2 - twoHundredFifty), hundred, sizeLetters, WHITE);
	drawButton(MenuMusicButton);
	DrawText("Tronik", (screenWidth / 2 + hundred), (hundred + 10), sizeLetters, RED);
	if (isButtonPressed(MenuMusicButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://suno.com/song/1f50ed34-cad9-45c1-a778-1daaa4bc162e");
	}

	DrawText("Gameplay Music: ", (screenWidth / 2 - twoHundredFifty), (twoHundred - 20), sizeLetters, WHITE);
	drawButton(gameplayMusicButton);
	DrawText("Tronik", (screenWidth / 2 + hundred), (twoHundred - 10), sizeLetters, RED);
	if (isButtonPressed(gameplayMusicButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://suno.com/song/8bd8538e-799e-4c38-b2b6-80c1e0cb0327");
	}


	DrawText("Click SFX By: ", (screenWidth / 2 - twoHundredFifty), (twoHundredFifty + 10), sizeLetters, WHITE);
	drawButton(clickSfxButton);
	DrawText("Pixaby", (screenWidth / 2 + hundred), (twoHundredFifty + 20), sizeLetters, RED);
	if (isButtonPressed(clickSfxButton))
	{
		PlaySound(clickSfx);
		OpenURL("https://pixabay.com/sound-effects/click-234708/");
	}

	DrawText("vacio: ", (screenWidth / 2 - twoHundredFifty), (threeHundredFifty - 10), sizeLetters, WHITE);
	drawButton(explosionSfxButton);
	DrawText("vacio", (screenWidth / 2 + hundred), threeHundredFifty, sizeLetters, RED);
	if (isButtonPressed(explosionSfxButton))
	{
		PlaySound(clickSfx);
		//OpenURL("https://www.zapsplat.com/music/8bit-medium-explosion-bomb-boom-or-blast-cannon-retro-old-school-classic-cartoon/");
	}

	DrawText("vacio: ", (screenWidth / 2 - twoHundredFifty), (fourHundredFifty - 30), sizeLetters, WHITE);
	drawButton(loseSfxButton);
	DrawText("vacio", (screenWidth / 2 + hundred), (fourHundredFifty - 20), sizeLetters, RED);
	if (isButtonPressed(loseSfxButton))
	{
		PlaySound(clickSfx);
		//OpenURL("https://www.zapsplat.com/music/cartoon-orchestral-musical-pizzicato-riff-short-fail-or-lose/");
	}

	DrawText("vacio: ", (screenWidth / 2 - twoHundredFifty), fiveHundred, sizeLetters, WHITE);
	drawButton(boostSfxButton);
	DrawText("vacio", (screenWidth / 2 + fifty), (fiveHundred + 10), sizeLetters, RED);
	if (isButtonPressed(boostSfxButton))
	{
		PlaySound(clickSfx);
		//OpenURL("https://elevenlabs.io/app/sound-effects/history");
	}

	DrawText("vacio: ", (screenWidth / 2 - twoHundredFifty), (fiveHundred + 80), sizeLetters, WHITE);
	drawButton(shootSfxButton);
	DrawText("vacio", (screenWidth / 2 + hundred), (fiveHundred + 90), sizeLetters, RED);
	if (isButtonPressed(shootSfxButton))
	{
		PlaySound(clickSfx);
		//OpenURL("https://www.zapsplat.com/music/anime-hard-and-fast-laser-shoot-3/");
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


