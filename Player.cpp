#include "Player.h"

Player::Player(void)
{
}

Player::~Player(void)
{
}

void Player::setUsername(string name) {
	userName = name;
}

string Player::getUsername() {
	return userName;
}

void Player::setScore(int userScore) {
	score = userScore;
}

int Player::getScore() {
	return score;
}