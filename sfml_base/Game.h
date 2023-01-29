#pragma once
#include <SFML/Graphics.hpp>
#include "SoundPlayer.h"

using namespace sf;

class Game
{
private:
	RenderWindow* window;
	SoundPlayer* soundPlayer;

	CircleShape shape, shape_integrada;

	Clock clock;
	Time delta;
	float deltaTime;
	float totalTime = 0;

	struct {
		bool leftArrow;
		bool rightArrow;
		bool upArrow;
		bool downArrow;
		bool space;
	} listeningKeys;

	bool playing = false;

	void loop();
	void update();
	void draw();

public:
	Game();
	~Game();
};

