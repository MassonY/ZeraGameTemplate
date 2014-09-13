#ifndef __Camera_h__
#define __Camera_h__

#include "const.h"
#include "Entity.h"

class Camera: public View
{
public: 
	Camera(const View &view);

	void centrerSur(Entity entity, RenderWindow &window);
};

#endif
