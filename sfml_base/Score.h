#pragma once
class Score
{
private:
	int avoidedItems;
	int total;

public:
	Score();
	void addOneItem();
	int getAvoidedItems();
	int getTotal();
};

