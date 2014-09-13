#ifndef __TileSetedMap_h__
#define __TileSetedMap_h__

#include "const.h"
#include "Tile.h"

class TileSetedMap
{
public:
	TileSetedMap(string chemin, string nomImgTile, string nomImgFond, int tailleTile, int nbTilesParLigne, int nbCaseX, int nbCaseY);

	void afficher(RenderWindow &window);

	Tile& getTile(int i, int j);
private:
	int nbCaseX, nbCaseY, tailleTile;

	Texture tTile, tFond;
	Sprite  sFond;

	vector<Tile> tiles;
};

#endif
