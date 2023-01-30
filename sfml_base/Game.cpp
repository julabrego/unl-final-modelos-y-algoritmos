#include "Game.h"

Game::Game()
{
	soundPlayer = new SoundPlayer();

	window = new RenderWindow(VideoMode(800, 600, 32), "New game");
	window->setFramerateLimit(60);

	gravity = 9.8f;

	ball = new Ball(gravity);
	arrow = new Arrow();

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
				/*listeningKeys.upArrow = Keyboard::isKeyPressed(Keyboard::Up);
				listeningKeys.downArrow = Keyboard::isKeyPressed(Keyboard::Down);*/
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

	ball->update(deltaTime);
	arrow->update(deltaTime);
	if (listeningKeys.leftArrow)
		arrow->rotateLeft();
	else if (listeningKeys.rightArrow)
		arrow->rotateRight();
	ball->setIsPressingActionBtn(listeningKeys.space, arrow->getDirection());
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
	arrow->draw(window);
}

Game::~Game()
{
	//delete window;
}
