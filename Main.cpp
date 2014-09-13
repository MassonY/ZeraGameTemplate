#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC


#include <SFML\Graphics.hpp>
#include <Box2D.h>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	window.setFramerateLimit(60);
	float32 timeStep = 1.0f / 60.0f;
	sf::CircleShape ball(50.f);
	ball.setFillColor(sf::Color::Green);
	ball.setPosition(sf::Vector2f(350, 100));

	sf::RectangleShape floor(sf::Vector2f(800,50));
	floor.setFillColor(sf::Color::Blue);
	floor.setPosition(sf::Vector2f(0, 550));

	b2Vec2 gravity(0.0f, 100.0f);
	b2World world(gravity);

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 600);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(800, 50);
	groundBody->CreateFixture(&groundBox, 0.0f);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(350, 100);

	b2Body* body = world.CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(100, 100);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		world.Step(timeStep, 6, 2);
		ball.setPosition(sf::Vector2f(body->GetPosition().x, body->GetPosition().y));
		std::cout << body->GetPosition().x << " " << body->GetPosition().y << std::endl;
		window.clear();
		window.draw(ball);
		window.draw(floor);
		window.display();
	}

	return 0;
}