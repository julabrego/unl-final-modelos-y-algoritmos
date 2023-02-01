#include "HUD.h"
#include <iostream>
HUD::HUD()
{
	rectanguloBottom = new sf::RectangleShape(sf::Vector2f(960.0f, 50.0f));
	rectanguloBottom->setFillColor(sf::Color::Black);
	rectanguloBottom->setPosition(0, 600 - rectanguloBottom->getSize().y);

	if (!font.loadFromFile("assets/dogicapixelbold.ttf"));

	textosBottom.setFont(font);
	textosBottom.setString("Vidas: 3 - Puntos: 100");
	textosBottom.setCharacterSize(26);
	textosBottom.setFillColor(sf::Color::White);
	textosBottom.setPosition(rectanguloBottom->getPosition().x + 10, rectanguloBottom->getPosition().y + 10);

	titulo.setFont(font);
	titulo.setCharacterSize(50);
	titulo.setFillColor(sf::Color::White);
	titulo.setOrigin(titulo.getScale().x, titulo.getScale().y);

	subtitulo.setFont(font);
	subtitulo.setCharacterSize(26);
	subtitulo.setFillColor(sf::Color::White);

	rectanguloBotonJugar = new sf::RectangleShape(sf::Vector2f(200.0f, 50.0f));
	rectanguloBotonJugar->setFillColor(sf::Color::White);
	rectanguloBotonJugar->setOutlineThickness(5.0f);
	rectanguloBotonJugar->setOutlineColor(sf::Color::Black);
	rectanguloBotonJugar->setPosition(380, 310);

	textoBotonJugar.setFont(font);
	textoBotonJugar.setCharacterSize(26);
	textoBotonJugar.setString("Jugar");
	textoBotonJugar.setFillColor(sf::Color::Black);
	textoBotonJugar.setPosition(rectanguloBotonJugar->getPosition().x + 35, rectanguloBotonJugar->getPosition().y + 10);

}

void HUD::pantallaMenuPrincipal() {
	titulo.setString("EL JUEGO DE LA PELOTITA");
	subtitulo.setString("");

	titulo.setPosition(400 - titulo.getGlobalBounds().width / 2, 200);
	subtitulo.setPosition(400 - subtitulo.getGlobalBounds().width, 260);

	mostrarTitulo = true;
	mostrarSubtitulo = true;
}
void HUD::pantallaGameOver()
{
	titulo.setString("GAME OVER");
	subtitulo.setString("Puntos: " + std::to_string(this->puntos));

	titulo.setPosition(400 - titulo.getGlobalBounds().width / 2, 200);
	subtitulo.setPosition(400 - subtitulo.getGlobalBounds().width, 260);

	mostrarTitulo = true;
	mostrarSubtitulo = true;
}

void HUD::update(int vidas, int puntos)
{
	this->vidas = vidas;
	this->puntos = puntos;

	textosBottom.setString("Vidas: " + std::to_string(this->vidas) + " | Puntos: " + std::to_string(this->puntos));
}


void HUD::draw(sf::RenderWindow* window)
{
	if (!mostrarTitulo && !mostrarSubtitulo) {
		window->draw(*this->rectanguloBottom);
		window->draw(this->textosBottom);
	}

	if (mostrarTitulo) {
		window->draw(this->titulo);
	}

	if (mostrarSubtitulo) {
		window->draw(this->subtitulo);
		window->draw(*this->rectanguloBotonJugar);
		window->draw(this->textoBotonJugar);
	}

}

void HUD::setMostrarTitulo(bool mostrarTitulo)
{
	this->mostrarTitulo = mostrarTitulo;
}

bool HUD::getMostrarTitulo()
{
	return mostrarTitulo;
}

void HUD::ocultarTituloYSubtitulo()
{
	mostrarTitulo = false;
	mostrarSubtitulo = false;
}

void HUD::setMostrarSubtitulo(bool mostrarSubtitulo)
{
	this->mostrarSubtitulo = mostrarSubtitulo;
}

bool HUD::getMostrarSubtitulo()
{
	return mostrarSubtitulo;
}

void HUD::mostrarCuentaRegresiva(int numero)
{
	titulo.setPosition(400 - titulo.getGlobalBounds().width / 2, 200);

	if (numero != 0) {
		titulo.setString(std::to_string(numero));
	}
	else {
		titulo.setString("YA!");
	}

	mostrarTitulo = true;
	mostrarSubtitulo = false;
}

bool HUD::manejarClickSobreBotonJugar(sf::Vector2f mousePosicion)
{
	sf::FloatRect bounds = rectanguloBotonJugar->getGlobalBounds();

	return (bounds.contains(mousePosicion));
}
