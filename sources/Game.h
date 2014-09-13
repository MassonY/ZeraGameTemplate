#ifndef __Game_h__
#define __Game_h__

#include "const.h"
#include "TileSetedMap.h"
#include "Camera.h"
#include "Player.h"

class Game
{
public:
	Game(RenderWindow& _window);

	void run();

private:
	RenderWindow& window;

	TileSetedMap map;
	Camera camera;
	Player zerator;
};

#endif
