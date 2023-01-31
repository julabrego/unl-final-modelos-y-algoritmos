#pragma once
#include <SFML/Graphics.hpp>
#include "SoundPlayer.h"
#include "Ball.h"
#include "Item.h"
#include "Score.h"

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

	Ball *ball;
	Item* items[5];

	Score score;

	float spawnFrequency = 3.f;
	float holdingToSpawn = 0.f;

	int nextItem = -1;

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

