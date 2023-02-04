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
	RectangleShape hitbox;
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

	int color = 0;
	void generateColor();
	sf::Color AVAILABLE_COLORS[4] = { sf::Color::Blue, sf::Color::Red, sf::Color::Green, sf::Color::Magenta };

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
	void setMaxSpeed(float maxSpeed);
	float getMaxSpeed();
	bool isMoving();

	bool handleCollisionWithPlayer(RectangleShape playersHitbox);
	int getColor();

	void showTextScore(std::string text);
	void hideTextScore();
	int getPositionY();
};

