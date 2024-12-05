#include "player.h"

#include "objects/utils.h"

void initPlayer(Player& p)
{
	p.position = { static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2 - 100 };
	p.speed = { 200, 200 };
	p.height = 100;
	p.width = 100;
	p.gravity = 500;
	p.score = 0;
	p.hasCollided = false;
	p.life = 3;
}

void updatePlayer(Player& p)
{
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
		p.position.x = static_cast<float>(screenWidth) / 2;
		p.position.y = static_cast<float>(screenHeight) / 2;
		p.speed.x = 200;
		p.speed.y = 200;
	}

	p.speed.y += p.gravity * GetFrameTime();
	
	p.position.y += p.speed.y * GetFrameTime();
	
	if (IsKeyDown(KEY_SPACE))
		p.speed.y = antiGravity;
}

void drawPlayer(Player& p)
{
	DrawRectangle(static_cast<int>(p.position.x), static_cast<int>(p.position.y), p.width, p.height, RED);
	DrawText(TextFormat(" Life: % 01i", p.life), screenWidthMin, screenHeightMin, 30, RED);
	DrawText(TextFormat(" Points: %01i", p.score), screenWidth - 200, screenHeightMin, 30, RED);

}
