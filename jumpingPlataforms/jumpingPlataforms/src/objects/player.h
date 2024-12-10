#pragma once

#include "raylib.h"

struct Player
{
	Vector2 position;
	Vector2 speed;
	int height;
	int width;
	int gravity;
	int score;
	int life;
};

void initPlayer(Player& p);
void loadTexturePlayer();
void updatePlayer(Player& p, bool& gameOver);
void drawPlayer(Player& p);