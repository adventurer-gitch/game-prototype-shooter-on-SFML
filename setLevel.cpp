#include "Player.h"

void MyNamespace::Player::setLevel(boost::multiprecision::cpp_int level)
{
	this->level = level + 1;
}