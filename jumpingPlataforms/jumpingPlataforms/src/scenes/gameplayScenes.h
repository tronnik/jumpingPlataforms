#pragma once

#include "objects/player.h"
#include "objects/plataforms.h"

void gameplayInit();

bool checkCollision(Player p, Plataform plat);

void doCollision();

void gameplayUpdate();

void gameplayDraw();

