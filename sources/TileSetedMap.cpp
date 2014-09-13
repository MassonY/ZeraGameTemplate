#include "TileSetedMap.h"
#include "Game.h"

TileSetedMap::TileSetedMap(string chemin, string nomImgTile, string nomImgFond, int tailleTile, int nbTilesParLigne, int nbCaseX, int nbCaseY) :
	nbCaseX(nbCaseX), nbCaseY(nbCaseY), tailleTile(tailleTile)
{
	if (!tTile.loadFromFile(nomImgTile)) {
		cout << "image inexistante : " << nomImgTile << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	ifstream F(chemin);
	if (!F) {
		cout << "ERREUR: Impossible d'ouvrir le fichier " << chemin << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	else {
		cout << "\nmap : \n";

		int num;
		for (int j = 0; j < nbCaseY; j++) {
			for (int i = 0; i < nbCaseX; i++) {
				F >> num;
				cout <<num << " ";

				tiles.push_back( Tile(tTile, num) );
				getTile(i, j).setPosition((float)tailleTile * i, (float)tailleTile * j);

				int posX = (num - 1) % nbTilesParLigne * tailleTile;
				int posY = (num - 1) / nbTilesParLigne * tailleTile;
				getTile(i,j).setTextureRect(IntRect(posX, posY, tailleTile, tailleTile));
			}
			cout << endl;
		}
	}

	if (!tFond.loadFromFile(nomImgFond)) {
		cout << "image inexistante : " << nomImgFond << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	sFond.setTexture(tFond);
}

void TileSetedMap::afficher(RenderWindow &window) {
	window.draw(sFond);

	for (int i = 0; i < nbCaseX; i++) {
		for (int j = 0; j < nbCaseY; j++) {
			window.draw(getTile(i, j));
		}
	}
}

Tile& TileSetedMap::getTile(int i, int j) {
	return tiles[j*nbCaseX + i];
}