#include "Ball.h"

void Ball::restartPosition()
{
	positionX = startPositionX;
	positionY = startPositionY;
}

void Ball::resetParams()
{
	velocityX = velocityY = initialVelocityY = .0f;
}

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
	startPositionX = positionX = 400 - shape.getRadius();
	startPositionY = positionY = 10;

	shotStep = ShotStep::STILL;

}

void Ball::update(float deltaTime)
{
	if (moving) {
		std::cout << "initial: " << velocityY << std::endl;
		velocityY += gravity;

		// Resistencia cuando sube
		if (velocityY < 0) {
			velocityY += std::abs(velocityY) * .025;
		}

		// bounce();
	}

	// Caída hasta el borde inferior de la pantalla
	if (positionY >= 600 - shape.getRadius() && velocityY > 0) {
		restartPosition();
		resetParams();
		shotStep = ShotStep::STILL;
		moving = false;
	}
	// Actualización de coordenadas
	positionX += velocityX * deltaTime;
	positionY += velocityY * deltaTime;

	// Nueva posición
	shape.setPosition(positionX, positionY);

	if (isPressingActionBtn) {
		if (shotStep == ShotStep::STILL) {
			startCharge();
		}

		if (shotStep == ShotStep::CHARGING) {
			charge();
		}
	}
	else if (shotStep == ShotStep::CHARGING) {
		shot();
	}

}

void Ball::bounce()
{
	velocityY = -velocityY * 0.9;
}

void Ball::startCharge()
{
	std::cout << "Start charging" << std::endl;
	shotStep = ShotStep::CHARGING;
}

void Ball::charge() {
	if (isChargingUp) initialVelocityY++; else initialVelocityY--;

	if (initialVelocityY < 0) isChargingUp = true;
	if (initialVelocityY > 100) isChargingUp = false;

	std::cout << initialVelocityY << std::endl;
}


void Ball::draw(RenderWindow* window)
{
	window->draw(shape);
}

void Ball::setIsPressingActionBtn(bool isPressing)
{
	isPressingActionBtn = isPressing;
}

void Ball::shot()
{
	std::cout << "Release" << std::endl;
	shotStep = ShotStep::SHOOTING;
	velocityY = initialVelocityY * 10;
	if (!moving) moving = true;
}
