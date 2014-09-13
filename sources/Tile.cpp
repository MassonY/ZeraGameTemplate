#include "Tile.h"

Tile::Tile() {
}

Tile::Tile(Texture &t, int num) : Sprite(t), num(num) {
}
