#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
class Ball
{
	CircleShape shape;
	float startPositionX = .0f;
	float startPositionY = .0f;
	float initialVelocityY = .0f;
	float initialVelocityX = .0f;
	float positionX = .0f;
	float positionY = .0f;
	float velocityX = .0f;
	float velocityY = .0f;
	float gravity = .0f;

	bool moving = false;
	bool isPressingActionBtn;

	void restartPosition();
	void resetParams();

	bool isChargingUp = true;

	enum class ShotStep {
		STILL,
		CHARGING,
		SHOOTING
	};
	ShotStep shotStep = ShotStep::STILL;

public:
	Ball();
	Ball(float gravity);

	void update(float deltaTime);
	void bounce();

	void startCharge();
	void shot();
	void charge();

	void setIsPressingActionBtn(bool isPressing, float direction);

	void draw(RenderWindow* window);
};

