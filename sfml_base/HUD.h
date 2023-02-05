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

	sf::RectangleShape* rectangleBottom;
	sf::Text textsBottom;

	sf::Text title;
	sf::Text subtitle;
	sf::Text instructions;

	sf::RectangleShape* rectangleButtonPlay;
	sf::Text textButtonPlay;

	sf::RectangleShape* backToMainMenuButton;
	sf::Text textBackToMainMenuButton;

	bool showTitle = false;
	bool showSubtitle = false;
	bool showInstructions = false;

public:
	HUD(Score* score, int* time);
	void mainMenuScreen();
	void centerTitleAndSubtitle();
	void gameOverScreen();

	void setShowTitle(bool showTitle);
	bool getShowTitle();

	void setShowSubtitle(bool showSubtitle);
	bool getShowSubtitle();

	void hideTitleAndSubtitle();

	bool handleClickButtonPlay(sf::Vector2f mousePosition);
	bool handleClickButtonBackToMainMenu(sf::Vector2f mousePosition);

	void update();
	void draw(sf::RenderWindow* window);
};

