#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
class Arrow
{
private:
	RectangleShape rectangle;
	float positionX = .0f;
	float positionY = .0f;
	float direction = 0.0f;

public:
	Arrow();
	void rotateLeft();
	void rotateRight();

	void update(float deltaTime);
	void draw(RenderWindow *window);
};

