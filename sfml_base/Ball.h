#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
class Ball
{
private:
	CircleShape shape;
	float startPositionX = .0f;
	float startPositionY = .0f;
	float initialVelocityX = .0f;
	float positionX = .0f;
	float positionY = .0f;
	float velocityX = .0f;
	float horizontalAcceleration = 10.0f;
	float maxHorizontalSpeed = 300.f;

	bool isMovingLeft = false;
	bool isMovingRight = false;

	bool playing = true;
	bool isPressingActionBtn;

	void restartPosition();

public:
	Ball();

	void update(float deltaTime);
	void bounce();

	void setIsMovingLeft(bool isMovingLeft);
	void setIsMovingRight(bool isMovingRight);

	void draw(RenderWindow* window);
};

