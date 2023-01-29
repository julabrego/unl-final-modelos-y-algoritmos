#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
class Ball
{
	CircleShape shape;
	float positionX = .0f;
	float positionY = .0f;
	float velocityX = .0f;
	float velocityY = .0f;
	float gravity = .0f;;

public:
	Ball();
	Ball(float gravity);

	void update(float deltaTime);
	void draw(RenderWindow* window);
};

