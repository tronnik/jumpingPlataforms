#include "gameplayScenes.h"

Player player;

static int addPoints = 10;

static float reduceVelocity = -200.0f;

void gameplayInit()
{
	initPlayer(player);
	initPlataform();
}

bool checkCollision(Player p, Plataform plat)
{
	if (p.position.x + p.width >= plat.position.x &&
		p.position.x <= plat.position.x + plat.width &&
		p.position.y + p.height >= plat.position.y &&
		p.position.y <= plat.position.y + plat.height)
	{
		return true;
	}
	return false;
}

void doCollision()
{
	if (checkCollision(player, plataform))
	{
		if (!player.hasCollided)
		{
			player.score += addPoints;
			player.hasCollided = true;
		}
		player.speed.y = reduceVelocity;
	}
	else
	{
		player.hasCollided = false;
	}
}

void gameplayUpdate()
{
	updatePlayer(player);
	updatePlataform();
	doCollision();
}

void gameplayDraw()
{
	drawPlayer(player);
	drawPlataform();


}
