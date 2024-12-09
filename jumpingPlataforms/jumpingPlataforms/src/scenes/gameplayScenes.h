#pragma once

#include "objects/player.h"
#include "objects/plataforms.h"

void gameplayInit();

void loadGameplayTextures();

bool checkCollision(Player p, Plataform plat);

void doCollision();

void gameplayUpdate();

void gameplayDraw();

void unloadGameplay();

