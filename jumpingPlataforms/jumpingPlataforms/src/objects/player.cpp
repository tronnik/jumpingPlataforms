#include "player.h"

void initPlayer(Player& p)
{
	p.position = { 640 / 2, 480 / 2};
	p.speed = { 20, 20 };
	p.height = 100;
	p.width = 100;
	p.gravity = 0;
}

void updatePlayer(Player& p)
{
	if (IsKeyDown(KEY_A)) p.position.x -= p.speed.x * GetFrameTime();
	if (IsKeyDown(KEY_D)) p.position.x += p.speed.x * GetFrameTime();
}

void drawPlayer(Player& p)
{
	DrawRectangle(static_cast<int>(p.position.x), static_cast<int>(p.position.y), p.width, p.height, RED);
}
