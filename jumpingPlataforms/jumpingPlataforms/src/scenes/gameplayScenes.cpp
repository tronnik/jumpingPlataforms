#include "gameplayScenes.h"

#include "objects/player.h"
#include "objects/plataforms.h"

Player player;
Plataform plataform;

void gameplayInit()
{
	initPlayer(player);
	initPlataform();
}

void gameplayUpdate()
{
	updatePlayer(player);
	updatePlataform();
}

void gameplayDraw()
{
	drawPlayer(player);
	drawPlataform();

}
