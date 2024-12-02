#include "player.h"

#include "objects/utils.h"

void initPlayer(Player& p)
{
	p.position = { 640 / 2, 480 / 2};
	p.speed = { 150, 150 };
	p.height = 100;
	p.width = 100;
	p.gravity = 500;
}

void updatePlayer(Player& p)
{
	float reduceVelocity = -200.0f;

	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) p.position.x -= p.speed.x * GetFrameTime();
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) p.position.x += p.speed.x * GetFrameTime();

	if (p.position.x + p.width >= screenWidth)
	{
		p.position.x = static_cast<float>(screenWidth) - static_cast<float>(p.width);
	}

	if (p.position.x <= screenWidthMin)
	{
		p.position.x = static_cast<float>(screenWidthMin);
	}

	if (p.position.y <= screenHeightMin)
	{
		p.position.y = static_cast<float>(screenHeightMin);
	}

	p.speed.y += p.gravity * GetFrameTime();
	
	p.position.y += p.speed.y * GetFrameTime();
	
	if (IsKeyDown(KEY_SPACE))
		p.speed.y = reduceVelocity;
}

void drawPlayer(Player& p)
{
	DrawRectangle(static_cast<int>(p.position.x), static_cast<int>(p.position.y), p.width, p.height, RED);
}
