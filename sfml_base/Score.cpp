#include "Score.h"

Score::Score()
{
	avoidedItems = 0;
	total= 0;
}

void Score::addOneItem()
{
	avoidedItems++;
	total = avoidedItems * 100;
}

int Score::getAvoidedItems()
{
	return avoidedItems;
}

void Score::substractOneItem()
{
	if(avoidedItems > 0)
		avoidedItems--;
	total = avoidedItems * 100;
}

int Score::getTotal()
{
	return total;
}
