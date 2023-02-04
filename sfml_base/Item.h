#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Score.h"
#include <ctime>
#include <stdlib.h>

using namespace sf;

class Item
{
private:
	float speed = 0;
	CircleShape circle;
	Texture texture;
	Sprite sprite;
	RectangleShape hitbox;
	std::string* AVAILABLE_COLORS;

	Score* _score;

	sf::Font font;
	sf::Text textScore;
	bool textScoreVisibility = false;
	int timeScoreBeingVisible = 0;

	float startPositionX = .0f;
	float startPositionY = .0f;
	float initialVelocityX = .0f;
	float positionX = .0f;
	float positionY = .0f;
	float velocityY = .0f;
	float acceleration = 10.0f;
	float maxSpeed = 200.0f;
	float initialMaxSpeed = maxSpeed;

	int color = 0;
	void generateColor();

	bool moving = false;

public:
	Item();
	Item(Score* score, std::string* availableColors);
	void update(float deltaTime);
	void draw(RenderWindow *window);
	void setPositionX(float positionX);
	void resetPositionY();
	void reachTop();
	void stop();
	void start();
	void setMaxSpeed(float maxSpeed);
	float getMaxSpeed();
	bool isMoving();

	bool handleCollisionWithPlayer(RectangleShape playersHitbox);
	int getColor();

	void showTextScore(std::string text);
	void hideTextScore();
	int getPositionY();
	void resetInitialMaxSpeed();
};

