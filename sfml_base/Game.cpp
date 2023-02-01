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
	hud = new HUD();

	items[0] = new Item(&score);
	items[1] = new Item(&score);
	items[2] = new Item(&score);
	items[3] = new Item(&score);
	items[4] = new Item(&score);
	items[5] = new Item(&score);
	items[6] = new Item(&score);
	items[7] = new Item(&score);
	items[8] = new Item(&score);
	items[9] = new Item(&score);
	items[10] = new Item(&score);

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

			if (currentFase != Fase::PLAYING && hud->getMostrarTitulo()) {
				if (e.type == Event::MouseButtonReleased) {
					mousePosicion = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
					if (hud->manejarClickSobreBotonJugar(mousePosicion)) {
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
	delta = clock.restart();
	deltaTime = delta.asSeconds();
	totalTime += deltaTime;
	holdingToSpawn += deltaTime;

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

		// Spawnear item cada cierto tiempo
		if (holdingToSpawn > spawnFrequency) {
			holdingToSpawn = 0;

			// spawn item en posición random
			do {
				nextItem = rand() % 11;
				std::cout << nextItem << std::endl;
			} while (items[nextItem]->isMoving());

			items[nextItem]->start();
			nextItem = -1;

			// Se cuelga
			if (score.getAvoidedItems() > 0 && score.getAvoidedItems() % 2 == 0) {
				if (spawnFrequency > 0.6) spawnFrequency = spawnFrequency - .5f;

				for (Item* item : items) {
					if (item->getMaxSpeed() < 500)
						item->setMaxSpeed(item->getMaxSpeed() + 10);
					std::cout << "max speed: " << item->getMaxSpeed() << std::endl;
				};

				if (spawnFrequency < 0.6) spawnFrequency = 0.6;
			}
		}
		else if (currentFase == Fase::GAME_OVER) {

		}

	}

	// Check collisions
	for (Item* item : items) {
		if (item->handleCollisionWithPlayer(ball->getHitbox())) {
			if (item->getColor() == ball->getColor()) {
				score.addOneItem();
			}
			else {
				score.substractOneItem();
			}
			ball->generateColor();
		}
	}
}

/**
* Método para dibujar los elementos en juego
*/
void Game::draw()
{
	if (currentFase == Fase::MAIN_MENU) {
		hud->pantallaMenuPrincipal();
	}
	else if (currentFase == Fase::PLAYING) {
		hud->ocultarTituloYSubtitulo();
		ball->draw(window);

		for (Item* item : items) {
			item->draw(window);
		}
	}
	else if (currentFase == Fase::GAME_OVER) {
		hud->pantallaGameOver();
	}

	hud->draw(window);
}

Game::~Game()
{
	//delete window;
}

void Game::startGame()
{
	//vidas = 3;
	//puntos = 0;
	//npcsAbatidos = 0;
	//escenario->setMaximoEnPantalla(1);

	//cuentaRegresiva = 4;
	currentFase = Fase::PLAYING;
	playing = true;
}
