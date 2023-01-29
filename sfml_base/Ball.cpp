#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(float gravity)
{
	this->gravity = gravity;

	// Seteo círculo de color verde
	shape = CircleShape(25.f);
	shape.setFillColor(sf::Color(100, 250, 50));

	// Posición inicial
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

	// Caída hasta el borde inferior de la pantalla
	if (positionY >= 600 - shape.getRadius() && velocityY > 0) {
		velocityY = -velocityY * 0.9;
	}

	// Actualización de coordenadas
	positionX += velocityX * deltaTime;
	positionY += velocityY * deltaTime;

	// Nueva posición
	shape.setPosition(positionX, positionY);

}

void Ball::draw(RenderWindow* window)
{
	window->draw(shape);
}
