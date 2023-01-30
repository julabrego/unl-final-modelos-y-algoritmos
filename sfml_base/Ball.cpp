#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(float gravity)
{
	this->gravity = gravity;

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

void Ball::resetParams()
{
	velocityX = velocityY = initialVelocityY = .0f;
}


void Ball::update(float deltaTime)
{
	if (moving) {
		//std::cout << "initial: " << velocityY << std::endl;
		velocityY += gravity;

		// Resistencia cuando sube
		if (velocityY < 0) {
			velocityY += std::abs(velocityY) * .025;
		}

		// bounce();
	}

	// Ca�da hasta el borde inferior de la pantalla
	if (positionY >= 600 - shape.getRadius() && velocityY > 0) {
		restartPosition();
		resetParams();
		shotStep = ShotStep::STILL;
		moving = false;
	}
	// Actualizaci�n de coordenadas
	positionX += velocityX * deltaTime;
	positionY += velocityY * deltaTime;

	// Nueva posici�n
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

void Ball::setIsPressingActionBtn(bool isPressing, float direction)
{
	isPressingActionBtn = isPressing;
	initialVelocityX = direction;
}

void Ball::shot()
{
	std::cout << "Release" << std::endl;
	shotStep = ShotStep::SHOOTING;
	velocityY = initialVelocityY * 10;
	
	std::cout << std::abs(initialVelocityY) - std::abs(initialVelocityX) << std::endl;
	if (!moving) moving = true;
}
