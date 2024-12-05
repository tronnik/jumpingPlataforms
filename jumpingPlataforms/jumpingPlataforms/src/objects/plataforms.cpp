#include "plataforms.h"

#include <iostream>

#include "objects/utils.h"

//Plataform plataforms[maxPlataforms];
Plataform plataform;
void initPlataform()
{
	plataform.space = 250.0f;
	plataform.position = { static_cast<float>(GetRandomValue(screenWidthMin, screenWidth)), static_cast<float>(screenHeight) / 2 };
	plataform.speedY = 100;
	plataform.height = 25;
	plataform.width = 150;
	plataform.gravity = 200;


	//for (int i = 0; i < maxPlataforms; i++)
	//{
	//	plataforms[i].space = 250.0f;
	//	plataforms[i].position = { static_cast<float>(GetRandomValue(screenWidthMin, screenWidth)), -i * plataforms->space };
	//	plataforms[i].speedY = 100;
	//	plataforms[i].height = 25;
	//	plataforms[i].width = 150;
	//	plataforms[i].gravity = 200;
	//}
}

void updatePlataform()
{
	plataform.speedY += plataform.gravity * GetFrameTime();
	
	plataform.position.y += plataform.speedY * GetFrameTime();
	
	if (plataform.position.x + plataform.width >= screenWidth)
	{
		plataform.position.x = static_cast<float>(screenWidth) - static_cast<float>(plataform.width);
	}

	if (plataform.position.x <= screenWidthMin)
	{
		plataform.position.x = static_cast<float>(screenWidthMin);
	}

	if (plataform.position.y > screenHeight)
	{
		plataform.position.y = static_cast<float>(screenHeightMin);
		plataform.position.x = static_cast<float>(GetRandomValue(screenWidthMin + plataform.width, screenWidth - plataform.width));
		plataform.speedY = 200;
	}
	
	//for (int i = 0; i < maxPlataforms; i++)
	//{
	//	plataforms[i].speedY += plataforms[i].gravity * GetFrameTime();
	//
	//	plataforms[i].position.y += plataforms[i].speedY * GetFrameTime();
	//
	//	if (plataforms[i].position.y > screenHeight)
	//	{
	//		plataforms[i].position.y = static_cast<float>(screenHeightMin);
	//		plataforms[i].position.x = static_cast<float>(GetRandomValue(screenWidthMin + plataforms->width, screenWidth - plataforms->width));
	//		plataforms[i].speedY = 200;
	//	}
	//}
}

void drawPlataform()
{
	DrawRectangle(static_cast<int>(plataform.position.x), static_cast<int>(plataform.position.y), plataform.width, plataform.height, RED);

	//for (int i = 0; i < maxPlataforms; i++)
	//{
	//	DrawRectangleV(plataforms[i].position, { static_cast<float>(plataforms[i].width), static_cast<float>(plataforms[i].height) }, DARKGRAY);
	//}
}
