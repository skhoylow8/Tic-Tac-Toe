#include "Player.h"

/**
This is the constructor that takes in 2 parameters
@param player_name is the first value and stores the players name
@param score is the second value and stores the players score
*/
Player::Player(const std::string& player_name, int score) : name(player_name), score(0) {}

/**
This function returns the name of the player
@return the name of the players
*/
const std::string Player::get_name() const
{
	return name;
}

/**
This function sets the score of the players according to if they won and it increases it by 1
*/
void Player::set_score()
{
	score += 1;
}

/**
This function returns the players score
@return the player scores
*/
const int Player::get_score() const
{
	return score;
}