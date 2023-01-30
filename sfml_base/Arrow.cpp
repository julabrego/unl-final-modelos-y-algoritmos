#include "Arrow.h"


Arrow::Arrow()
{
	// Seteo círculo de color verde
	rectangle = RectangleShape(Vector2f(8.f, 100.f));
	rectangle.setFillColor(sf::Color(0, 0, 200));
	rectangle.setOrigin(4.f, 0.f);

	positionX = 400.f;
	positionY = 30.f;
}

void Arrow::rotateLeft()
{
	if (direction >= -90)
		direction--;
	std::cout << direction << std::endl;
}

void Arrow::rotateRight()
{
	if(direction <= 90)
		direction++;
	std::cout << direction << std::endl;
}

void Arrow::update(float deltaTime)
{
	rectangle.setPosition(positionX, positionY);
	rectangle.setRotation(direction);
}

void Arrow::draw(RenderWindow* window)
{
	window->draw(rectangle);
}

float Arrow::getDirection()
{
	return direction;
}
