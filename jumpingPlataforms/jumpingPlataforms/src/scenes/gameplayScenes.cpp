#include "gameplayScenes.h"

Player player;

static int addPoints = 1;

static float reduceVelocity = -200.0f;

void gameplayInit()
{
	initPlayer(player);
	initPlataform();
}

void loadGameplayTextures()
{
	loadTexturePlayer();
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

	for (int i = 0; i < maxPlataforms; i++)
	{
		if (checkCollision(player, plataforms[i]))
		{
			if (!plataforms[i].hasCollided)
			{
				player.score += addPoints;
				plataforms[i].hasCollided = true; 
			}
			player.speed.y = reduceVelocity;
		}
		else
		{
			plataforms[i].hasCollided = false; 
		}
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
