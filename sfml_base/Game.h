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
	float secondsCounter = 0;

	Ball *ball;
	Item* items[11];

	Score* score;
	HUD* hud;

	Texture textureBackground;
	Sprite spriteBackground;

	int nextSoundIndex = 0;
	SoundPlayer::SoundName ballHitSounds[8] = {
		SoundPlayer::SoundName::C4,
		SoundPlayer::SoundName::D4,
		SoundPlayer::SoundName::E4,
		SoundPlayer::SoundName::F4,
		SoundPlayer::SoundName::G4,
		SoundPlayer::SoundName::A4,
		SoundPlayer::SoundName::B4,
		SoundPlayer::SoundName::C5,
	};

	std::string AVAILABLE_COLORS[5] = {
		"ORANGE_PANTONE",
		"WINTER_SKY",
		"BLUE_VIOLET",
		"AZURE"
	};
	
	float spawnFrequency = 2.f;
	float initialSpawnFrequency = spawnFrequency;
	float holdingToSpawn = 0.f;
	int timeCounter = 0;

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
	void endGame();
};


