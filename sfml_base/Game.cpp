#include "Game.h"

Game::Game()
{
	soundPlayer = new SoundPlayer();

	window = new RenderWindow(VideoMode(800, 600, 32), "New game");
	window->setFramerateLimit(60);

	// set the shape color to green
	shape = CircleShape(50.f);
	shape.setFillColor(sf::Color(100, 250, 50));

	// shape integrada red
	shape_integrada = CircleShape(50.f);
	shape_integrada.setFillColor(sf::Color(250, 50, 50));

	playing = true;

	pos_exacta.x = 0;
	pos_exacta.y = desplazamiento_inicial;

	pos_integrada.x = 0;
	pos_integrada.y = desplazamiento_inicial + 100;

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
				listeningKeys.upArrow = Keyboard::isKeyPressed(Keyboard::Up);
				listeningKeys.downArrow = Keyboard::isKeyPressed(Keyboard::Down);
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

	if (listeningKeys.leftArrow) shape.move(-1, 0);
	if (listeningKeys.rightArrow) shape.move(1, 0);
	if (listeningKeys.upArrow) shape.move(0, -1);
	if (listeningKeys.downArrow) shape.move(0, 1);
	if (listeningKeys.space) soundPlayer->play(SoundPlayer::SoundName::Ejemplo1);
}

/** 
* Método para dibujar los elementos en juego
*/
void Game::draw()
{
	if (playing) {
		// player->draw(window);
	}

	window->draw(shape);
	window->draw(shape_integrada);
}

Game::~Game()
{
	//delete window;
}
