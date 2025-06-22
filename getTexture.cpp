#include "Map.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

sf::Texture& MyNamespace::Map::getTexture()
{
	return this->texture;
}

sf::Texture& MyNamespace::Player::getTexture()
{
	return this->texture;
}

sf::Texture& MyNamespace::Bullet::getTexture()
{
	return this->texture;
}

sf::Texture& MyNamespace::Enemy::getTexture()
{
	return this->texture;
}