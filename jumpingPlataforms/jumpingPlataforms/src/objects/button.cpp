#include "objects/button.h"

#include "raylib.h"

#include "objects/utils.h"
#include "gameLoop/game.h"

Button button;
Button controls;
Button credits;
Button backToMenu;
Button exitGame;
Button pauseGame;
Button resumeGame;
Button playAgain;
Button page1;
Button page2;

static int thirty = 30;
static int forty = 40;
static int seventy = 70;
static int eighty = 80;
static int hundred = 100;
static int twoHundred = 200;

static int threeHundredSixty = 360;
static int fourHundredSixty = 460;
static int fiveHundredSixty = 560;
static int sixHundredSixty = 660;
static int sevenHundredTen = 710;


void initButton(Button& b, int xPos, int yPos)
{
	b.posX = xPos;
	b.posY = yPos;
	b.width = 200;
	b.height = 50;
}

void initPageButton(Button& b, int xPos, int yPos)
{
	b.posX = xPos;
	b.posY = yPos;
	b.width = 50;
	b.height = 50;
}

void drawButton(Button& b)
{
	Color buttonColor = CheckCollisionPointRec(GetMousePosition(),
		Rectangle{ static_cast<float>(b.posX), static_cast<float>(b.posY),
		static_cast<float>(b.width), static_cast<float>(b.height) }) ? DARKGRAY : LIGHTGRAY;

	DrawRectangle(b.posX, b.posY, b.width, b.height, buttonColor);
}

bool isButtonPressed(Button& b)
{
	return CheckCollisionPointRec(GetMousePosition(),
		Rectangle{ static_cast<float>(b.posX), static_cast<float>(b.posY),
		static_cast<float>(b.width), static_cast<float>(b.height) }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void createPlayButton(bool& menuOn)
{
	initButton(button, screenWidth / 2 - forty, threeHundredSixty);
	drawButton(button);
	DrawText(TextFormat("PLAY"), screenWidth / 2 - forty, 360, sizeLetters, RED);
	if (isButtonPressed(button))
	{
		//PlaySound(clickSfx);

		menuOn = false;

		//resetGame();
	}
}

void createCreditsButton(bool& creditsOn, bool& menuOn)
{
	initButton(credits, screenWidth / 2 - seventy, fourHundredSixty);
	drawButton(credits);
	DrawText(TextFormat("CREDITS"), screenWidth / 2 - seventy, fourHundredSixty, sizeLetters, RED);
	if (isButtonPressed(credits))
	{
		//PlaySound(clickSfx);

		creditsOn = true;
		menuOn = false;

	}
}

void createControlsButton(bool& controlsOn, bool& menuOn)
{
	initButton(controls, screenWidth / 2 - eighty, fiveHundredSixty);
	drawButton(controls);
	DrawText(TextFormat("CONTROLS"), screenWidth / 2 - eighty, fiveHundredSixty, sizeLetters, RED);
	if (isButtonPressed(controls))
	{
		//PlaySound(clickSfx);

		controlsOn = true;
		menuOn = false;

	}

}

void createExitButton()
{
	initButton(exitGame, screenWidth / 2 - forty, sixHundredSixty);
	drawButton(exitGame);
	DrawText(TextFormat("EXIT"), screenWidth / 2 - forty, sixHundredSixty, sizeLetters, RED);
	if (isButtonPressed(exitGame))
	{
		//PlaySound(clickSfx);

		close();

	}
}


void drawBackToMenuTitle()
{
	DrawText(TextFormat("MENU"), screenWidth / 2 + hundred + 10, sevenHundredTen, sizeLetters, RED);
}

void drawPauseButtonTitle()
{
	DrawText(TextFormat("PAUSE"), screenWidth - twoHundred, screenHeight - hundred + 10, sizeLetters, RED);
}

void drawResumeGameTitle()
{
	DrawText(TextFormat("RESUME"), screenWidth / 2 - hundred - 60, sevenHundredTen, sizeLetters, RED);
}

void drawPlayAgainTitle()
{
	DrawText(TextFormat("PLAY AGAIN"), screenWidth / 2 - twoHundred + 10, sevenHundredTen, sizeLetters, RED);
}

void drawPage1Title()
{
	DrawText(TextFormat("1"), screenWidth / 2 - hundred - thirty, sevenHundredTen, sizeLetters, RED);
}

void drawPage2Title()
{
	DrawText(TextFormat("2"), screenWidth / 2 - thirty, sevenHundredTen, sizeLetters, RED);
}

