#pragma once

#include "raylib.h"

namespace jumpingPlataform
{
	struct Plataform
	{
		float space;
		Vector2 position;
		float speedY;
		int height;
		int width;
		int gravity;
		bool hasCollided = false;
	};

	const int maxPlataforms = 6;
	extern Plataform plataforms[maxPlataforms];

	void initPlataform();
	void loadPlataformTexture();
	void updatePlataform();
	void drawPlataform();
}

