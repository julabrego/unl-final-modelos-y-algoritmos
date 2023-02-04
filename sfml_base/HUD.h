#pragma once
#include <SFML/Graphics.hpp>
#include "Score.h"

class HUD
{
private:
	Score* _score;
	int* _timeCounter;

	sf::Texture texture;
	sf::Font font;

	sf::RectangleShape* rectanguloBottom;
	sf::Text textosBottom;

	sf::Text titulo;
	sf::Text subtitulo;

	sf::RectangleShape* rectanguloBotonJugar;
	sf::Text textoBotonJugar;

	bool mostrarTitulo = false;
	bool mostrarSubtitulo = false;

public:
	HUD(Score* score, int* time);
	void pantallaMenuPrincipal();
	void pantallaGameOver();

	void setMostrarTitulo(bool mostrarTitulo);
	bool getMostrarTitulo();

	void setMostrarSubtitulo(bool mostrarSubtitulo);
	bool getMostrarSubtitulo();

	void ocultarTituloYSubtitulo();

	bool manejarClickSobreBotonJugar(sf::Vector2f mousePosicion);

	void mostrarCuentaRegresiva(int numero);
	void update();
	void draw(sf::RenderWindow* window);
};

