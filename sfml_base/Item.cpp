#include "Item.h"

void Item::generateColor()
{
	color = rand() % 4;
	circle.setFillColor(AVAILABLE_COLORS[color]);
}

Item::Item()
{
}

Item::Item(Score* score)
{
	srand(time(NULL));

	// Seteo círculo de color verde
	circle = CircleShape(20.f);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	// Hitbox
	hitbox = RectangleShape(Vector2f(30, 30));
	hitbox.setFillColor(sf::Color(255, 255, 0, 100));
	hitbox.setOrigin(15, 15);

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
	hitbox.setPosition(positionX, positionY);
}

void Item::draw(RenderWindow* window)
{
	window->draw(circle);
	//window->draw(hitbox);
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
}

void Item::stop()
{
	moving = false;
	velocityY = 0;
}

void Item::start()
{
	moving = true;
	generateColor();
}

void Item::setMaxSpeed(float maxSpeed)
{
	this->maxSpeed = maxSpeed;
}
float Item::getMaxSpeed()
{
	return this->maxSpeed;
}

bool Item::isMoving()
{
	return moving;
}

bool Item::handleCollisionWithPlayer(RectangleShape playersHitbox)
{
	if (hitbox.getGlobalBounds().intersects(playersHitbox.getGlobalBounds())) {
		reachTop();
		return true;
	}
	return false;
}

int Item::getColor()
{
	return color;
}
