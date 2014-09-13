#ifndef __Player_h__
#define __Player_h__

#include "Walkable.h"

class Player : public Walkable
{
public:
	Player(string cheminImg, float posX, float posY);

	void deplacement();

private:
	Clock timer;
};

#endif
