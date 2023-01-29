#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(float gravity)
{
	this->gravity = gravity;

	// Seteo c�rculo de color verde
	shape = CircleShape(25.f);
	shape.setFillColor(sf::Color(100, 250, 50));

	// Posici�n inicial
	positionX = 400 - shape.getRadius();
	positionY = 10;

}

void Ball::update(float deltaTime)
{
	velocityY += gravity;


	// Resistencia cuando sube
	if (velocityY < 0) {
		velocityY += std::abs(velocityY) * .025;
	}

	// Ca�da hasta el borde inferior de la pantalla
	if (positionY >= 600 - shape.getRadius() && velocityY > 0) {
		velocityY = -velocityY * 0.9;
	}

	// Actualizaci�n de coordenadas
	positionX += velocityX * deltaTime;
	positionY += velocityY * deltaTime;

	// Nueva posici�n
	shape.setPosition(positionX, positionY);

}

void Ball::draw(RenderWindow* window)
{
	window->draw(shape);
}
