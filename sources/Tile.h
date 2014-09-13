#ifndef __Tile_h__
#define __Tile_h__

#include "const.h"

class Tile: public Sprite
{
public:
	Tile();
	Tile(Texture &t, int num);

private:
	int num;
};

#endif
