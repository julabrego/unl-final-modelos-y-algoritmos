#include "Game.h"

Game::Game()
{
	soundPlayer = new SoundPlayer();

	window = new RenderWindow(VideoMode(800, 600, 32), "New game");
	window->setFramerateLimit(60);

	gravity = 9.8f;

	ball = new Ball(gravity);

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
				/*listeningKeys.leftArrow = Keyboard::isKeyPressed(Keyboard::Left);
				listeningKeys.rightArrow = Keyboard::isKeyPressed(Keyboard::Right);
				listeningKeys.upArrow = Keyboard::isKeyPressed(Keyboard::Up);
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
	//if (listeningKeys.leftArrow) shape.move(-1, 0);
	//if (listeningKeys.rightArrow) shape.move(1, 0);
	//if (listeningKeys.upArrow) shape.move(0, -1);
	//if (listeningKeys.downArrow) shape.move(0, 1);
	//if (listeningKeys.space) soundPlayer->play(SoundPlayer::SoundName::Ejemplo1);
	ball->setIsPressingActionBtn(listeningKeys.space);
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
}

Game::~Game()
{
	//delete window;
}
