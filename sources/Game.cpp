#include "Game.h"

Game::Game(RenderWindow& _window) : window(_window), camera(window.getView()),
	map(	 (string)CHEMIN_MAP + (string)"niv1.txt", (string)CHEMIN_IMG + (string)"grass.png", (string)CHEMIN_IMG + (string)"ciel.jpg", 64, 8, 15, 10),
	zerator( (string)CHEMIN_IMG + (string)"knight.png", window.getSize().x / 2.f, window.getSize().y / 2.f)
{
	zerator.setTextureRect(IntRect(0, 0, 70, 90));
}

void Game::run() {
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		zerator.deplacement();
		camera.centrerSur(zerator, window);

		window.clear();		
		map.afficher(window);
		window.draw(zerator);
		window.display();
	}
}