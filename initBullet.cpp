#include "Game.h"

void MyNamespace::Game::initBullet()
{
	this->bullets.getImage().loadFromFile("Images/bullet.png");
	this->bullets.getImage().createMaskFromColor(sf::Color(255, 255, 255));
	this->bullets.getTexture().loadFromImage(this->bullets.getImage());
	this->bullets.getSprite().setTexture(this->bullets.getTexture());
	this->bullets.getSprite().setScale(this->window_size.width / this->grand_window_size_width, this->window_size.height / this->grand_windwo_size_height);
	this->bullets.getSprite().setOrigin((float)this->bullets.getImage().getSize().x / 2, (float)this->bullets.getImage().getSize().y / 2);
}