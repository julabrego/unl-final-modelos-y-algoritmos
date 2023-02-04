#pragma once
#include <SFML/Graphics.hpp>
#include "SoundPlayer.h"
#include "Ball.h"
#include "Item.h"
#include "Score.h"
#include "HUD.h"

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
	Item* items[11];

	Score* score;
	HUD* hud;

	double spawnFrequency = .8f;
	double holdingToSpawn = 0.f;

	int nextItem = -1;
	sf::Vector2f mousePosicion;

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

	enum class Fase {
		MAIN_MENU,
		PLAYING,
		GAME_OVER
	};

	Fase currentFase = Fase::MAIN_MENU;

	void startGame();
};


