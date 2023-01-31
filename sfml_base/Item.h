#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Score.h"

using namespace sf;

class Item
{
private:
	float speed = 0;
	CircleShape circle;
	Score* _score;

	float startPositionX = .0f;
	float startPositionY = .0f;
	float initialVelocityX = .0f;
	float positionX = .0f;
	float positionY = .0f;
	float velocityY = .0f;
	float acceleration = 10.0f;
	float maxSpeed = 200.0f;

	bool moving = false;

public:
	Item();
	Item(Score* score);
	void update(float deltaTime);
	void draw(RenderWindow *window);
	void setPositionX(float positionX);
	void resetPositionY();
	void reachTop();
	void stop();
	void start();
	bool isMoving();
};

