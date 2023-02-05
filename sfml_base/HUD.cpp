#include "HUD.h"
#include <iostream>
HUD::HUD(Score* score, int* timeCounter)
{
	_score = score;
	_timeCounter = timeCounter;

	rectangleBottom = new sf::RectangleShape(sf::Vector2f(960.0f, 50.0f));
	rectangleBottom->setFillColor(sf::Color::Black);
	rectangleBottom->setPosition(0, 600 - rectangleBottom->getSize().y);

	if (!font.loadFromFile("assets/dogicapixelbold.ttf"));

	textsBottom.setFont(font);
	textsBottom.setString("-");
	textsBottom.setCharacterSize(20);
	textsBottom.setFillColor(sf::Color::White);
	textsBottom.setPosition(rectangleBottom->getPosition().x + 10, rectangleBottom->getPosition().y + 10);

	title.setFont(font);
	title.setCharacterSize(50);
	title.setFillColor(sf::Color::White);

	subtitle.setFont(font);
	subtitle.setCharacterSize(26);
	subtitle.setFillColor(sf::Color::White);

	instructions.setFont(font);
	instructions.setCharacterSize(18);
	instructions.setFillColor(sf::Color::White);

	rectangleButtonPlay = new sf::RectangleShape(sf::Vector2f(200.0f, 50.0f));
	rectangleButtonPlay->setOrigin(rectangleButtonPlay->getGlobalBounds().width / 2, rectangleButtonPlay->getGlobalBounds().height / 2);
	rectangleButtonPlay->setFillColor(sf::Color::White);
	rectangleButtonPlay->setOutlineThickness(5.0f);
	rectangleButtonPlay->setOutlineColor(sf::Color::Black);
	rectangleButtonPlay->setPosition(800 / 2, 350);

	textButtonPlay.setFont(font);
	textButtonPlay.setCharacterSize(26);
	textButtonPlay.setString("Jugar");
	textButtonPlay.setOrigin(textButtonPlay.getGlobalBounds().width / 2, textButtonPlay.getGlobalBounds().height / 2);
	textButtonPlay.setFillColor(sf::Color::Black);
	textButtonPlay.setPosition(rectangleButtonPlay->getPosition().x, rectangleButtonPlay->getPosition().y);

	backToMainMenuButton = new sf::RectangleShape(sf::Vector2f(45.0f, 45.0f));
	backToMainMenuButton->setOrigin(backToMainMenuButton->getGlobalBounds().width / 2, backToMainMenuButton->getGlobalBounds().height / 2);
	backToMainMenuButton->setFillColor(sf::Color::White);
	backToMainMenuButton->setOutlineThickness(2.5f);
	backToMainMenuButton->setOutlineColor(sf::Color::Black);
	backToMainMenuButton->setPosition(800 - backToMainMenuButton->getGlobalBounds().width / 2, 600 - backToMainMenuButton->getGlobalBounds().height / 2);

	textBackToMainMenuButton.setFont(font);
	textBackToMainMenuButton.setString("<<");
	textBackToMainMenuButton.setOrigin(textBackToMainMenuButton.getGlobalBounds().width / 2, textBackToMainMenuButton.getGlobalBounds().height / 2);
	textBackToMainMenuButton.setCharacterSize(22);
	textBackToMainMenuButton.setFillColor(sf::Color::Black);
	textBackToMainMenuButton.setPosition(backToMainMenuButton->getPosition().x, backToMainMenuButton->getPosition().y);
}

void HUD::mainMenuScreen() {
	title.setString("La bocha loca");
	subtitle.setString("Juntá los colores");

	centerTitleAndSubtitle();

	instructions.setString("Mover la pelota usando los cursores y\n\nrecolectar las otras pelotas del mismo color.");
	instructions.setOrigin(instructions.getGlobalBounds().width / 2, instructions.getGlobalBounds().height / 2);
	instructions.setPosition(400, 560);

	showTitle = true;
	showSubtitle = true;
	showInstructions = true;
}
void HUD::centerTitleAndSubtitle()
{
	title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	title.setPosition(400, 200);

	subtitle.setOrigin(subtitle.getGlobalBounds().width / 2, subtitle.getGlobalBounds().height / 2);
	subtitle.setPosition(400, 275);
}
void HUD::gameOverScreen()
{
	title.setString("GAME OVER");
	subtitle.setString("Score: " + std::to_string(this->_score->getTotal()) + " | High score: " + std::to_string(this->_score->getHighScore()));

	centerTitleAndSubtitle();

	showTitle = true;
	showSubtitle = true;
}

void HUD::update()
{
	textsBottom.setString("Score: " + std::to_string(this->_score->getTotal()) + " | Tiempo: " + std::to_string(*_timeCounter) + " | High score: " + std::to_string(this->_score->getHighScore()));
}


void HUD::draw(sf::RenderWindow* window)
{
	if (!showTitle && !showSubtitle) {
		window->draw(*this->rectangleBottom);
		window->draw(this->textsBottom);

		window->draw(*this->backToMainMenuButton);
		window->draw(this->textBackToMainMenuButton);
	}

	if (showTitle) {
		window->draw(this->title);
	}

	if (showSubtitle) {
		window->draw(this->subtitle);
		window->draw(*this->rectangleButtonPlay);
		window->draw(this->textButtonPlay);
	}

	if (showInstructions) {
		window->draw(this->instructions);
	}

}

void HUD::setShowTitle(bool mostrarTitulo)
{
	this->showTitle = mostrarTitulo;
}

bool HUD::getShowTitle()
{
	return showTitle;
}

void HUD::hideTitleAndSubtitle()
{
	showTitle = false;
	showSubtitle = false;
	showInstructions = false;
}

void HUD::setShowSubtitle(bool mostrarSubtitulo)
{
	this->showSubtitle = mostrarSubtitulo;
}

bool HUD::getShowSubtitle()
{
	return showSubtitle;
}

bool HUD::handleClickButtonPlay(sf::Vector2f mousePosicion)
{
	sf::FloatRect bounds = rectangleButtonPlay->getGlobalBounds();

	return (bounds.contains(mousePosicion));
}

bool HUD::handleClickButtonBackToMainMenu(sf::Vector2f mousePosition)
{
	sf::FloatRect bounds = backToMainMenuButton->getGlobalBounds();

	return (bounds.contains(mousePosition));
}
