#include "Game.h"
#include <ctime>
#include <stdlib.h>

Game::Game()
{
	srand(time(NULL));
	soundPlayer = new SoundPlayer();

	window = new RenderWindow(VideoMode(800, 600, 32), "New game");
	window->setFramerateLimit(60);

	if (!textureBackground.loadFromFile("assets/background.jpg"))
		std::cout << "No se encontró la textura" << std::endl;

	spriteBackground.setTexture(textureBackground);
	spriteBackground.setOrigin(spriteBackground.getGlobalBounds().width / 2, spriteBackground.getGlobalBounds().height / 2);
	spriteBackground.setPosition(400, 300);

	ball = new Ball(AVAILABLE_COLORS);
	score = new Score();
	hud = new HUD(score, &timeCounter);

	items[0] = new Item(score, AVAILABLE_COLORS);
	items[1] = new Item(score, AVAILABLE_COLORS);
	items[2] = new Item(score, AVAILABLE_COLORS);
	items[3] = new Item(score, AVAILABLE_COLORS);
	items[4] = new Item(score, AVAILABLE_COLORS);
	items[5] = new Item(score, AVAILABLE_COLORS);
	items[6] = new Item(score, AVAILABLE_COLORS);
	items[7] = new Item(score, AVAILABLE_COLORS);
	items[8] = new Item(score, AVAILABLE_COLORS);
	items[9] = new Item(score, AVAILABLE_COLORS);
	items[10] = new Item(score, AVAILABLE_COLORS);

	for (int i = 0; i < 11; i++) {
		items[i]->setPositionX(((window->getSize().x / 11) * i) + (window->getSize().x / 11) / 2);
	}

	playing = true;

	loop();
}

/**
* Game loop
*/
void Game::loop()
{
	Event e;
	while (window->isOpen()) {
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed)
				window->close();

			if (currentFase != Fase::PLAYING && hud->getShowTitle()) {
				if (e.type == Event::MouseButtonReleased) {
					mousePosicion = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
					if (hud->handleClickButtonPlay(mousePosicion)) {
						startGame();
					}
				}
			}

			if (currentFase == Fase::PLAYING) {
				listeningKeys.leftArrow = Keyboard::isKeyPressed(Keyboard::Left);
				listeningKeys.rightArrow = Keyboard::isKeyPressed(Keyboard::Right);
				listeningKeys.space = Keyboard::isKeyPressed(Keyboard::Space);
			}
		}

		update();
		window->clear();
		draw();
		window->display();
	}
}
/**
* Método para actualizar el estado de los elementos en juego
*/
void Game::update()
{
	deltaTime = clock.restart().asSeconds();
	totalTime += deltaTime;
	holdingToSpawn += deltaTime;
	secondsCounter += deltaTime;

	if (currentFase == Fase::MAIN_MENU) {
		//hud->pantallaMenuPrincipal();
	}
	else if (currentFase == Fase::PLAYING) {
		ball->update(deltaTime);

		if (listeningKeys.leftArrow)
			ball->setIsMovingLeft(true);
		else
			ball->setIsMovingLeft(false);

		if (listeningKeys.rightArrow)
			ball->setIsMovingRight(true);
		else
			ball->setIsMovingRight(false);

		for (Item* item : items) {
			item->update(deltaTime);
		}

		// Check collisions
		for (Item* item : items) {
			if (item->handleCollisionWithPlayer(ball->getHitbox())) {
				if (item->getColor() == ball->getColor()) {
					score->add(100);
					item->showTextScore("+100");

					if (nextSoundIndex <= 7) {
						soundPlayer->play(ballHitSounds[nextSoundIndex]);
						nextSoundIndex++;
					}
					else {
						nextSoundIndex = 0;
					}
				}
				else {
					score->substract(100);
					item->showTextScore("-100");
					soundPlayer->play(SoundPlayer::SoundName::MISS);
					nextSoundIndex = 0;
				}
				ball->generateColor();
			}

			if (item->getPositionY() < 0) {
				if (item->getColor() == ball->getColor()) {
					item->showTextScore("-50");
					score->substract(50);
					soundPlayer->play(SoundPlayer::SoundName::MISS);
				}
				item->reachTop();
			}
		}

		// Spawnear item cada cierto tiempo
		if (holdingToSpawn > spawnFrequency) {
			holdingToSpawn = 0;

			// spawn item en posición random
			do {
				nextItem = rand() % 11;
			} while (items[nextItem]->isMoving());

			items[nextItem]->start();
			nextItem = -1;

			// Cada 10 segundos subo la frecuencia de aparición y velocidad de los items
			if (timeCounter < 60 && timeCounter % 5 == 0) {
				if (spawnFrequency > 0.6) spawnFrequency = spawnFrequency - .25f;

				for (Item* item : items) {
					if (item->getMaxSpeed() < 500)
						item->setMaxSpeed(item->getMaxSpeed() + 10);
				};
			}

			if (spawnFrequency < 0.6) spawnFrequency = 0.6;
		}

		if (timeCounter > 0) {
			if (secondsCounter > 1) {
				secondsCounter = 0;
				timeCounter--;
			}
		}
		else {
			endGame();
		}

	}
	else if (currentFase == Fase::GAME_OVER) {

	}

	hud->update();
}

/**
* Método para dibujar los elementos en juego
*/
void Game::draw()
{
	window->draw(spriteBackground);

	if (currentFase == Fase::MAIN_MENU) {
		hud->mainMenuScreen();
	}
	else if (currentFase == Fase::PLAYING) {
		hud->hideTitleAndSubtitle();
		ball->draw(window);

		for (Item* item : items) {
			item->draw(window);
		}
	}
	else if (currentFase == Fase::GAME_OVER) {
		hud->gameOverScreen();
	}

	hud->draw(window);
}

Game::~Game()
{
	delete window;
}

void Game::startGame()
{
	timeCounter = 60;
	score->reset();
	currentFase = Fase::PLAYING;
	playing = true;
}

void Game::endGame()
{
	currentFase = Fase::GAME_OVER;
	ball->stop();
	ball->restartPosition();
	for (Item* item : items) {
		item->reachTop();
		item->stop();
		item->hideTextScore();
		item->resetInitialMaxSpeed();
	}
	score->setHighScore();
	nextSoundIndex = 0;
	spawnFrequency = initialSpawnFrequency;
}
