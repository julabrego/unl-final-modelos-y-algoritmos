#include "Ball.h"

Ball::Ball()
{
	// Seteo c�rculo de color verde
	shape = CircleShape(20.f);
	shape.setFillColor(sf::Color(100, 250, 50));
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	std::cout << "Radius: " << shape.getRadius() << std::endl;

	// Posici�n inicial
	startPositionX = positionX = 400;
	startPositionY = positionY = 30;

}

void Ball::restartPosition()
{
	positionX = startPositionX;
	positionY = startPositionY;
}

void Ball::update(float deltaTime)
{
	if (playing) {

		// Movimiento horizontal
		if (isMovingLeft && velocityX > -maxHorizontalSpeed)
			velocityX -= horizontalAcceleration;
		if (isMovingRight && velocityX < maxHorizontalSpeed)
			velocityX += horizontalAcceleration;

		if (!isMovingLeft && !isMovingRight || isMovingLeft && isMovingRight) {
			if (velocityX < 0) velocityX += horizontalAcceleration;
			else if (velocityX > 0) velocityX -= horizontalAcceleration;
			if (std::abs(velocityX < 30 && velocityX > 0)) velocityX = 0;
		}

	}

	if (positionX < shape.getRadius() || positionX > 800 - shape.getRadius()) bounce();

	// Actualizaci�n de coordenadas
	positionX += velocityX * deltaTime;

	// Nueva posici�n
	shape.setPosition(positionX, positionY);

	std::cout << velocityX << std::endl;

}

void Ball::bounce()
{
	velocityX = -velocityX * 0.9;
}

void Ball::setIsMovingLeft(bool isMovingLeft)
{
	this->isMovingLeft = isMovingLeft;
}

void Ball::setIsMovingRight(bool isMovingRight)
{
	this->isMovingRight = isMovingRight;
}

void Ball::draw(RenderWindow* window)
{
	window->draw(shape);
}

