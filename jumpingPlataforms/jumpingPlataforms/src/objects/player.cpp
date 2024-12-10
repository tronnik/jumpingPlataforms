#include "objects/player.h"

#include "objects/utils.h"

static Texture2D playerTexture;

static Sound loseLifeSfx;

static Sound gameOverSfx;

static Sound pointsSfx;

void initPlayer(Player& p)
{
	p.position = { static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2 - 100 };
	p.speed = { 700, 700 };
	p.height = 60;
	p.width = 50;
	p.gravity = 450;
	p.score = 0;
	p.life = 3;
}

void loadTexturePlayer()
{
	playerTexture = LoadTexture("res/player.png");
	loseLifeSfx = LoadSound("res/loseLifeSfx.mp3");
	gameOverSfx = LoadSound("res/gameOverSfx.mp3");
	pointsSfx = LoadSound("res/pointsSfx.mp3");

	SetSoundVolume(loseLifeSfx, 0.1f);
	SetSoundVolume(gameOverSfx, 0.3f);
	SetSoundVolume(pointsSfx, 0.3f);
}

void updatePlayer(Player& p, bool& gameOver)
{
	int lastSoundScore = 0;

	float antiGravity = -200.0f;

	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) p.position.x -= p.speed.x * GetFrameTime();
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) p.position.x += p.speed.x * GetFrameTime();

	if (p.position.x + p.width > screenWidth)
	{
		p.position.x = static_cast<float>(screenWidth) - static_cast<float>(p.width);
	}

	if (p.position.x < screenWidthMin)
	{
		p.position.x = static_cast<float>(screenWidthMin);
	}

	if (p.position.y < screenHeightMin)
	{
		p.position.y = static_cast<float>(screenHeightMin);
	}

	if (p.position.y > screenHeight)
	{
		p.life--;
		PlaySound(loseLifeSfx);
		p.position.x = static_cast<float>(screenWidth) / 2;
		p.position.y = static_cast<float>(screenHeight) / 2 - 200;
		p.speed.x = 700;
		p.speed.y = 700;
	}

	p.speed.y += p.gravity * GetFrameTime();

	p.position.y += p.speed.y * GetFrameTime();

	if (IsKeyDown(KEY_SPACE))
		p.speed.y = antiGravity;

	if (p.life == 0)
	{
		gameOver = true;
		PlaySound(gameOverSfx);
	}

	if (p.score % 10 == 0 && p.score != lastSoundScore)
	{
		PlaySound(pointsSfx);
		lastSoundScore = p.score;
	}
}

void drawPlayer(Player& p)
{
	float scale = 2.0f;

	DrawRectangle(static_cast<int>(p.position.x), static_cast<int>(p.position.y), p.width, p.height, RED);
	DrawText(TextFormat(" Life: % 01i", p.life), screenWidthMin, screenHeightMin, 30, RED);
	DrawText(TextFormat(" Points: %01i", p.score), screenWidth - 200, screenHeightMin, 30, RED);

	DrawTextureEx(playerTexture, { p.position.x - 5, p.position.y - 5}, 0.0f, scale, WHITE);
}
