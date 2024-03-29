#include "Item.h"

Item::Item()
{
}

Item::Item(Score* score, std::string* availableColors)
{
	srand(time(NULL));

	AVAILABLE_COLORS = availableColors;

	// Seteo c�rculo de color verde
	circle = CircleShape(20.f);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	// Hitbox
	hitbox = RectangleShape(Vector2f(30, 30));
	hitbox.setFillColor(sf::Color(255, 255, 0, 100));
	hitbox.setOrigin(15, 15);

	// Posici�n inicial
	startPositionY = positionY = 600 + circle.getRadius();

	_score = score;

	if (!font.loadFromFile("assets/dogicapixelbold.ttf"));

	textScore.setFont(font);
	textScore.setString("+100");
	textScore.setCharacterSize(16);
	textScore.setFillColor(sf::Color::White);
}

void Item::generateColor()
{
	color = rand() % 4;

	if (!texture.loadFromFile("assets/" + AVAILABLE_COLORS[color] + ".png"))
		std::cout << "No se encontr� la textura" << std::endl;

	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

void Item::update(float deltaTime)
{
	if (moving && velocityY > -maxSpeed) {
		velocityY -= acceleration;
	}

	// Actualizaci�n de coordenadas
	positionY += velocityY * deltaTime;

	// Nueva posici�n
	circle.setPosition(positionX, positionY);
	hitbox.setPosition(positionX, positionY);
	sprite.setPosition(positionX, positionY);

	// Text score 
	if (textScoreVisibility) {
		if (timeScoreBeingVisible > 0) {
			timeScoreBeingVisible--;
			textScore.setFillColor(sf::Color(255, 255, 255, timeScoreBeingVisible * 10 > 255 ? 255 : timeScoreBeingVisible * 10));
			textScore.move(0, -0.5f);
		}
		else {
			textScoreVisibility = false;
		}
	}
	else {
		textScore.setPosition(positionX - textScore.getGlobalBounds().width / 2, positionY);
	}
}

void Item::draw(RenderWindow* window)
{
	//window->draw(circle);
	//window->draw(hitbox);
	window->draw(sprite);

	// Text score 
	if (textScoreVisibility) {
		window->draw(textScore);
	}
}

void Item::setPositionX(float positionX)
{
	this->positionX = positionX;
}

void Item::resetPositionY()
{
	positionY = startPositionY;
}

void Item::reachTop()
{
	resetPositionY();
	stop();
}

void Item::stop()
{
	moving = false;
	velocityY = 0;
}

void Item::start()
{
	moving = true;
	generateColor();
}

void Item::setMaxSpeed(float maxSpeed)
{
	this->maxSpeed = maxSpeed;
}
float Item::getMaxSpeed()
{
	return this->maxSpeed;
}

bool Item::isMoving()
{
	return moving;
}

bool Item::handleCollisionWithPlayer(RectangleShape playersHitbox)
{
	if (hitbox.getGlobalBounds().intersects(playersHitbox.getGlobalBounds())) {
		reachTop();
		return true;
	}
	return false;
}

int Item::getColor()
{
	return color;
}

void Item::showTextScore(std::string text)
{
	textScore.setString(text);
	textScoreVisibility = true;
	timeScoreBeingVisible = 50;
}

void Item::hideTextScore()
{
	textScoreVisibility = false;
	timeScoreBeingVisible = 0;
}

int Item::getPositionY()
{
	return positionY;
}

void Item::resetInitialMaxSpeed()
{
	maxSpeed = initialMaxSpeed;
}
