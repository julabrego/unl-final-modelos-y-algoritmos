#pragma once
class Score
{
private:
	
	int highScore = 0;
	int total = 0;

public:
	Score();
	
	int getTotal();
	int getHighScore();
	void setHighScore(int score);

	void add(int value);
	void substract(int value);
};

