#include "Camera.h"

Camera::Camera(const View &view) : View(view) {
}

void Camera::centrerSur(Entity entity, RenderWindow &window) {
	setCenter(entity.getPosition());
	window.setView(*this);
}