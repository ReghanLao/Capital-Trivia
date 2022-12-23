#pragma once
#include <string>
using namespace std;

class Player
{
private:
	string userName;
	int score;
public:
	Player(void);
	~Player(void);
	void setUsername(string name);
	string getUsername();
	void setScore(int userScore);
	int getScore();
};