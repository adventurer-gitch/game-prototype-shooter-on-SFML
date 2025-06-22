#include "Map.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

sf::Image& MyNamespace::Map::getImage()
{
	return this->image;
}

sf::Image& MyNamespace::Player::getImage()
{
	return this->image;
}

sf::Image& MyNamespace::Enemy::getImage()
{
	return this->image;
}

sf::Image& MyNamespace::Bullet::getImage()
{
	return this->image;
}