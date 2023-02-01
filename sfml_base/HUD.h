#pragma once
#include <SFML/Graphics.hpp>

class HUD
{
private:
	sf::Texture texture;
	sf::Font font;

	sf::RectangleShape* rectanguloBottom;
	sf::Text textosBottom;

	sf::Text titulo;
	sf::Text subtitulo;

	sf::RectangleShape* rectanguloBotonJugar;
	sf::Text textoBotonJugar;

	int vidas, puntos = 0;
	bool mostrarTitulo = false;
	bool mostrarSubtitulo = false;

public:
	HUD();
	void pantallaMenuPrincipal();
	void pantallaGameOver();

	void setMostrarTitulo(bool mostrarTitulo);
	bool getMostrarTitulo();

	void setMostrarSubtitulo(bool mostrarSubtitulo);
	bool getMostrarSubtitulo();

	void ocultarTituloYSubtitulo();

	bool manejarClickSobreBotonJugar(sf::Vector2f mousePosicion);

	void mostrarCuentaRegresiva(int numero);
	void update(int vidas, int puntos);
	void draw(sf::RenderWindow* window);
};

