#pragma once
class Score
{
private:
	int avoidedItems;
	int total;

public:
	Score();
	void addOneItem();
	void substractOneItem();
	int getAvoidedItems();
	int getTotal();
};

