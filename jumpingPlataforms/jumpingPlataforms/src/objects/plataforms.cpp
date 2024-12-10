#include "objects/plataforms.h"

#include <iostream>

#include "objects/utils.h"

namespace jumpingPlataform
{
	static Texture2D plataformTexture;

	Plataform plataforms[maxPlataforms];

	void initPlataform()
	{
		const float initialY = static_cast<float>(screenHeight) / 2 + 50;

		for (int i = 0; i < maxPlataforms; i++)
		{
			plataforms[i].space = 250;

			plataforms[i].position = { static_cast<float>(GetRandomValue(screenWidthMin, screenWidth)), initialY - i * plataforms[i].space };

			plataforms[i].speedY = 100;
			plataforms[i].height = 25;
			plataforms[i].width = 150;
			plataforms[i].gravity = 150;
			plataforms[i].hasCollided = false;

		}

	}

	void loadPlataformTexture()
	{
		plataformTexture = LoadTexture("res/aliens.png");
	}

	void updatePlataform()
	{

		for (int i = 0; i < maxPlataforms; i++)
		{
			plataforms[i].speedY += plataforms[i].gravity * GetFrameTime();

			plataforms[i].position.y += plataforms[i].speedY * GetFrameTime();

			if (plataforms[i].position.x + plataforms[i].width >= screenWidth)
			{
				plataforms[i].position.x = static_cast<float>(screenWidth) - static_cast<float>(plataforms[i].width);
			}

			if (plataforms[i].position.x <= screenWidthMin)
			{
				plataforms[i].position.x = static_cast<float>(screenWidthMin);
			}

			if (plataforms[i].position.y > screenHeight)
			{
				plataforms[i].position.y = static_cast<float>(-plataforms[i].space);
				plataforms[i].position.x = static_cast<float>(GetRandomValue(50, 750));
				plataforms[i].speedY = 100;
				plataforms[i].gravity = 150;
			}
		}
	}

	void drawPlataform()
	{
		for (int i = 0; i < maxPlataforms; i++)
		{
			DrawTextureEx(plataformTexture, { plataforms[i].position.x, plataforms[i].position.y - 30 }, 0.0f, 5.0f, WHITE);
		}
	}
}
