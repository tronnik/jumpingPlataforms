#pragma once

#include "objects/player.h"
#include "objects/plataforms.h"

namespace jumpingPlataform
{
	void gameplayInit();

	void loadGameplayTextures();

	bool checkCollision(Player p, Plataform plat);

	void doCollision();

	void gameplayUpdate(bool& gameOver);

	void gameplayDraw(bool& menuOn, bool& pauseOn);

	void resetGame(bool& gameplayPaused);

	void unloadGameplay();
}

