#include "Score.h"
#include <iostream>

Score::Score()
{
	highScore = 0;
	total= 0;
}

int Score::getTotal()
{
	return total;
}

int Score::getHighScore()
{
	return highScore;
}

void Score::setHighScore()
{
	if (total > highScore) highScore = total;
}

void Score::add(int value)
{
	total += value;
}

void Score::substract(int value)
{
	if (total > 0) total -= value;
}

void Score::reset()
{
	total = 0;
}
