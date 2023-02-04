#include "Item.h"

Item::Item()
{
}

Item::Item(Score* score)
{
	srand(time(NULL));

	// Seteo círculo de color verde
	circle = CircleShape(20.f);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	// Hitbox
	hitbox = RectangleShape(Vector2f(30, 30));
	hitbox.setFillColor(sf::Color(255, 255, 0, 100));
	hitbox.setOrigin(15, 15);

	// Posición inicial
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
	circle.setFillColor(AVAILABLE_COLORS[color]);
}

void Item::update(float deltaTime)
{
	if (moving && velocityY > -maxSpeed) {
		velocityY -= acceleration;
	}

	// Actualización de coordenadas
	positionY += velocityY * deltaTime;

	// Nueva posición
	circle.setPosition(positionX, positionY);
	hitbox.setPosition(positionX, positionY);

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
}

void Item::draw(RenderWindow* window)
{
	window->draw(circle);
	//window->draw(hitbox);

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
		textScore.setPosition(positionX - textScore.getGlobalBounds().width / 2, positionY);
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

int Item::getPositionY()
{
	return positionY;
}
