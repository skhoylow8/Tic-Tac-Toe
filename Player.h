#ifndef _Player_
#define _Player_
#include <string>

class Player
{
public:
	Player(const std::string& player_name, int score);//stores the players names and scores
	const std::string get_name() const;//returns name
	const int get_score() const;//returns score
	void set_score();// score = score + 1

private:
	const std::string& name;
	int score;
};
#endif