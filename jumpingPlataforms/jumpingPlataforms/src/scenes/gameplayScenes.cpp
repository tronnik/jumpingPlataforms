#include "scenes/gameplayScenes.h"

#include "objects/utils.h"
#include "objects/button.h"
#include "scenes/pauseScene.h"
#include "scenes/gameplayPaused.h"

namespace jumpingPlataform
{
	static int addPoints = 1;

	static float reduceVelocity = -200.0f;

	static Texture2D background;
	static Sound jumpSfx;

	void gameplayInit()
	{
		initPlayer(player);
		initPlataform();
		initPauseButton();
	}

	void loadGameplayTextures()
	{
		loadTexturePlayer();
		loadPlataformTexture();
		background = LoadTexture("res/gameplaybackground.png");
		gameplayMusic = LoadMusicStream("res/gameplayMusic.mp3");
		jumpSfx = LoadSound("res/jumpSfx.mp3");

		SetMusicVolume(gameplayMusic, oneVolume);
		SetSoundVolume(jumpSfx, oneVolume);
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
					PlaySound(jumpSfx);
				}
				player.speed.y = reduceVelocity;
			}
			else
			{
				plataforms[i].hasCollided = false;
			}
		}
	}

	void gameplayUpdate(bool& gameOver)
	{
		PlayMusicStream(gameplayMusic);
		UpdateMusicStream(gameplayMusic);

		updatePlayer(player, gameOver);
		updatePlataform();
		doCollision();
	}

	void gameplayDraw(bool& menuOn, bool& pauseOn)
	{
		DrawTexture(background, 0, 0, LIGHTGRAY);
		drawPlayer(player);
		drawPlataform();

		drawButton(pauseGame);

		drawPauseButtonTitle();

		if (isButtonPressed(pauseGame))
		{
			pauseOn = true;
			menuOn = false;
		}
	}

	void resetGame(bool& gameplayPaused)
	{
		initPlayer(player);
		initPlataform();
		gameplayPaused = true;
	}

	void unloadGameplay()
	{
		UnloadTexture(background);
		UnloadMusicStream(gameplayMusic);
	}
}
