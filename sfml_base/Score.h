#pragma once
class Score
{
private:
	int avoidedItems = 0;
	int total = 0;

public:
	Score();
	void addOneItem();
	void substractOneItem();
	int getAvoidedItems();
	int getTotal();
};

