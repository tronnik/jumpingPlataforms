#include "objects/button.h"

#include "raylib.h"

#include "objects/utils.h"

namespace jumpingPlataform
{
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

	static int ten = 10;
	static int twnty = 20;
	static int thirty = 30;
	static int forty = 40;
	static int sixty = 60;
	static int seventy = 70;
	static int eighty = 80;
	static int hundred = 100;
	static int twoHundred = 200;

	static int threeHundredFifty = 350;
	static int fourHundredFifty = 450;
	static int fiveHundredFifty = 550;
	static int sixHundredFifty = 650;
	static int sevenHundred = 700;


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

	void drawPlayTitle()
	{
		DrawTextEx(fontGame, "PLAY", { static_cast<float>(screenWidth / 2 - forty), static_cast<float>(threeHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	}

	void drawControlTitle()
	{
		DrawTextEx(fontGame, "CREDITS", { static_cast<float>(screenWidth / 2 - seventy), static_cast<float>(fourHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	}

	void drawCreditsTitle()
	{
		DrawTextEx(fontGame, "CONTROLS", { static_cast<float>(screenWidth / 2 - eighty), static_cast<float>(fiveHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	}

	void drawExitTitle()
	{
		DrawTextEx(fontGame, "EXIT", { static_cast<float>(screenWidth / 2 - forty), static_cast<float>(sixHundredFifty) }, static_cast<float>(sizeLetters), 0.0f, RED);
	}

	void drawBackToMenuTitle()
	{
		DrawTextEx(fontGame, "MENU", { static_cast<float>(screenWidth / 2 + hundred), static_cast<float>(sevenHundred) }, static_cast<float>(sizeLetters), 0.0f, RED);
	}

	void drawPauseButtonTitle()
	{
		DrawTextEx(fontGame, "PAUSE", { static_cast<float>(screenWidth - twoHundred), static_cast<float>(screenHeight - hundred) }, static_cast<float>(sizeLetters), 0.0f, RED);
	}

	void drawResumeGameTitle()
	{
		DrawTextEx(fontGame, "RESUME", { static_cast<float>(screenWidth / 2 - hundred - sixty), static_cast<float>(sevenHundred) }, static_cast<float>(sizeLetters), 0.0f, RED);
	}

	void drawPlayAgainTitle()
	{
		DrawTextEx(fontGame, "PLAY AGAIN", { static_cast<float>(screenWidth / 2 - twoHundred + twnty), static_cast<float>(sevenHundred + ten) }, static_cast<float>(sizeLetters - ten), 0.0f, RED);
	}

	void drawPage1Title()
	{
		DrawTextEx(fontGame, "1", { static_cast<float>(screenWidth / 2 - hundred - thirty), static_cast<float>(sevenHundred) }, static_cast<float>(sizeLetters), 0.0f, RED);
	}

	void drawPage2Title()
	{
		DrawTextEx(fontGame, "2", { static_cast<float>(screenWidth / 2 - thirty), static_cast<float>(sevenHundred) }, static_cast<float>(sizeLetters), 0.0f, RED);
	}

}
