#pragma once
#include <SFML/Graphics.hpp>
#include "SoundPlayer.h"
#include "Ball.h"
#include "Arrow.h"

using namespace sf;

class Game
{
private:
	RenderWindow* window;
	SoundPlayer* soundPlayer;

	Clock clock;
	Time delta;
	float deltaTime;
	float totalTime = 0;

	float gravity;

	Ball *ball;
	Arrow *arrow;

	struct {
		bool leftArrow = false;
		bool rightArrow = false;
		bool upArrow = false;
		bool downArrow = false;
		bool space = false;
	} listeningKeys;

	bool playing = false;

	void loop();
	void update();
	void draw();

public:
	Game();
	~Game();
};

