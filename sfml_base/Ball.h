#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
class Ball
{
private:
	CircleShape shape;
	Texture texture;
	Sprite sprite;
	RectangleShape hitbox;
	std::string* AVAILABLE_COLORS;

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

	int color = 0;

public:
	Ball();
	Ball(std::string* availableColors);

	void restartPosition();
	void update(float deltaTime);
	void bounce();
	void stop();

	void setIsMovingLeft(bool isMovingLeft);
	void setIsMovingRight(bool isMovingRight);

	void draw(RenderWindow* window);
	int getColor();

	RectangleShape getHitbox();
	void generateColor();

};

