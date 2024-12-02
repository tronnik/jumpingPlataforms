#pragma once

#include "raylib.h"

struct Player
{
	Vector2 position;
	Vector2 speed;
	int height;
	int width;
	int gravity;
};



void initPlayer(Player& p);
void updatePlayer(Player& p);
void drawPlayer(Player& p);