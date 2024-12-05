#pragma once

#include "raylib.h"

struct Plataform
{
	float space;
	Vector2 position;
	float speedY;
	int height;
	int width;
	int gravity;
};

//const int maxPlataforms = 6;
//
//extern Plataform plataforms[maxPlataforms];

extern Plataform plataform;

void initPlataform();
void updatePlataform();
void drawPlataform();

