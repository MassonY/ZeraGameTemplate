#ifndef __Entity_h__
#define __Entity_h__

#include "const.h"

class Entity: public Sprite
{
public:
	Entity(string cheminImg);

private:
	Texture texture;
};

#endif
