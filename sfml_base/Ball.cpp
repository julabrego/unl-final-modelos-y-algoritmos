#include "Ball.h"

Ball::Ball() {
}

Ball::Ball(std::string* availableColors)
{
	AVAILABLE_COLORS = availableColors;

	// Seteo círculo de color verde
	shape = CircleShape(20.f);
	shape.setOrigin(shape.getRadius(), shape.getRadius());

	hitbox = RectangleShape(Vector2f(30, 30));
	hitbox.setFillColor(sf::Color(255, 255, 0, 100));
	hitbox.setOrigin(15, 15);

	// Posición inicial
	startPositionX = positionX = 400;
	startPositionY = positionY = 50;

	generateColor();
}

void Ball::generateColor()
{
	color = rand() % 4;
	
	if (!texture.loadFromFile("assets/" + AVAILABLE_COLORS[color] + ".png"))
		std::cout << "No se encontró la textura" << std::endl;

	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
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

	// Bordes de pantalla
	if (positionX < shape.getRadius()) {
		positionX = shape.getRadius();
		bounce();
	}

	if (positionX > 800 - shape.getRadius()) {
		positionX = 800 - shape.getRadius();
		bounce();
	}

	// Actualización de coordenadas
	positionX += velocityX * deltaTime;

	// Nueva posición
	shape.setPosition(positionX, positionY);
	hitbox.setPosition(positionX, positionY);
	sprite.setPosition(positionX, positionY);
}

void Ball::bounce()
{
	velocityX = -velocityX * 0.9;
}

void Ball::stop()
{
	velocityX = 0;
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
	//window->draw(shape);
	//window->draw(hitbox);
	window->draw(sprite);
}

int Ball::getColor()
{
	return color;
}

RectangleShape Ball::getHitbox()
{
	return hitbox;
}

