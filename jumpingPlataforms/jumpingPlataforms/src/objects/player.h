#pragma once

#include "raylib.h"

namespace jumpingPlataform
{
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

	extern 	Player player;

	void initPlayer(Player& p);
	void loadTexturePlayer();
	void updatePlayer(Player& p, bool& gameOver);
	void drawPlayer(Player& p);
}