#include "Game.h"
#include <ctime>
#include <stdlib.h>

Game::Game()
{
	srand(time(NULL));
	soundPlayer = new SoundPlayer();

	window = new RenderWindow(VideoMode(800, 600, 32), "New game");
	window->setFramerateLimit(60);

	ball = new Ball();
	score = Score();

	items[0] = new Item(&score);
	items[1] = new Item(&score);
	items[2] = new Item(&score);
	items[3] = new Item(&score);
	items[4] = new Item(&score);

	for (int i = 0; i < 5; i++) {
		std::cout << (window->getSize().x - 10 / 5 + 10) * i + 1 << std::endl;
		items[i]->setPositionX(((window->getSize().x / 5) * i) + (window->getSize().x / 5) / 2);
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

			if (playing) {
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
	delta = clock.restart();
	deltaTime = delta.asSeconds();
	totalTime += deltaTime;
	holdingToSpawn += deltaTime;

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

	// Spawnear item cada cierto tiempo
	if (holdingToSpawn > spawnFrequency) {
		holdingToSpawn = 0;

		// spawn item en posición random
		do {
			nextItem = rand() % 5;
		} while (items[nextItem]->isMoving());

		items[nextItem]->start();
		nextItem = -1;
	}
}

/**
* Método para dibujar los elementos en juego
*/
void Game::draw()
{
	if (playing) {
		// player->draw(window);
	}

	ball->draw(window);

	for (Item* item : items) {
		item->draw(window);
	}
}

Game::~Game()
{
	//delete window;
}
