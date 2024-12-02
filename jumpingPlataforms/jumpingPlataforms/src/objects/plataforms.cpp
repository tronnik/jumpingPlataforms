#include "plataforms.h"

#include <iostream>

#include "objects/utils.h"

Plataform plataforms[maxPlataforms];

void initPlataform()
{
	for (int i = 0; i < maxPlataforms; i++)
	{
		plataforms[i].position = { static_cast<float>(rand() % (800 - 150)), -i * 150.0f };
		plataforms[i].speedY = 200;
		plataforms[i].height = 25;
		plataforms[i].width = 150;
		plataforms[i].gravity = 100;
		plataforms[i].space = 50;
	}
}

void updatePlataform()
{
	for (int i = 0; i < maxPlataforms; i++)
	{
		plataforms[i].speedY += plataforms[i].gravity * GetFrameTime();

		plataforms[i].position.y += plataforms[i].speedY * GetFrameTime();

		if (plataforms[i].position.y > screenHeight)
		{
			plataforms[i].position.y = static_cast<float>(screenHeightMin);
			plataforms[i].position.x = static_cast<float>(rand() % (800 - plataforms[i].width));
			plataforms[i].speedY = 200;
		}
	}
}

void drawPlataform()
{
	for (int i = 0; i < maxPlataforms; i++)
	{
		DrawRectangleV(plataforms[i].position, { static_cast<float>(plataforms[i].width), static_cast<float>(plataforms[i].height) }, DARKGRAY);
	}
}
