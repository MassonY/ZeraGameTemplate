#include "Game.h"
#include "const.h"

int main()
{
	RenderWindow window(sf::VideoMode(960, 640), "Zeraventure");

	Game niveau1(window);
	niveau1.run();

	return 0;
}