#include "gameplayScenes.h"

#include "objects/player.h"

Player player;

void gameplayInit()
{
	initPlayer(player);

}

void gameplayUpdate()
{
	updatePlayer(player);

}

void gameplayDraw()
{
	drawPlayer(player);

}
