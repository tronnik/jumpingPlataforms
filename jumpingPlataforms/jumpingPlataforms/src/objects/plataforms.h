#pragma once

#include "raylib.h"

struct Plataform
{
	Vector2 position;
	float speedY;
	int height;
	int width;
	int gravity;
	int space;
};

const int maxPlataforms = 4;

extern Plataform plataforms[maxPlataforms];

void initPlataform();
void updatePlataform();
void drawPlataform();

