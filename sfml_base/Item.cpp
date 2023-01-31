#include "Item.h"

Item::Item()
{
}

Item::Item(Score* score)
{
	// Seteo círculo de color verde
	circle = CircleShape(20.f);
	circle.setFillColor(sf::Color(100, 0, 0));
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	// Posición inicial
	startPositionY = positionY = 600 + circle.getRadius();

	_score = score;
}

void Item::update(float deltaTime)
{
	if (moving && velocityY > -maxSpeed) {
		velocityY -= acceleration;
	}

	// Bordes de pantalla
	if (positionY < 0) {
		reachTop();
	}

	// Actualización de coordenadas
	positionY += velocityY * deltaTime;

	// Nueva posición
	circle.setPosition(positionX, positionY);

}

void Item::draw(RenderWindow* window)
{
	window->draw(circle);
}

void Item::setPositionX(float positionX)
{
	this->positionX = positionX;
}

void Item::resetPositionY()
{
	positionY = startPositionY;
}

void Item::reachTop()
{
	resetPositionY();
	stop();
	_score->addOneItem();
	std::cout << "avoided: " << _score->getAvoidedItems() << std::endl;
}

void Item::stop()
{
	moving = false;
	velocityY = 0;
}

void Item::start()
{
	moving = true;
}

bool Item::isMoving()
{
	return moving;
}
