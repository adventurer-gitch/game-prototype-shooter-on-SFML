#include "Map.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

sf::Sprite& 
MyNamespace::Map::getSprite()
{
	return this->sprire;
}

sf::Sprite& MyNamespace::Player::getSprite()
{
	return this->sprite;
}

sf::Sprite& MyNamespace::Bullet::getSprite()
{
	return this->sprite;
}

sf::Sprite& MyNamespace::Enemy::getSprite()
{
	return this->sprite;
}