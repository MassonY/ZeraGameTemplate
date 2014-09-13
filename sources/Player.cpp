#include "Player.h"

Player::Player(string cheminImg, float posX, float posY) : Walkable(cheminImg) {
	setPosition(posX, posY);
}

void Player::deplacement() {
	if (timer.getElapsedTime().asMilliseconds() > 30) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			move(-5, 0);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			move(5, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			move(0, -5);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			move(0, 5);

		timer.restart();
	}
}