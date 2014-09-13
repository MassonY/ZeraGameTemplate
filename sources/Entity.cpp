#include "Entity.h"

Entity::Entity(string cheminImg) {
	if (!texture.loadFromFile(cheminImg)) {
		cout << "image inexistante : " << cheminImg << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	setTexture(texture);
}