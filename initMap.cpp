#include "Game.h"

void MyNamespace::Game::initMap()
{
	this->map.getImage().loadFromFile("Images/fale_map_0.png");
	this->map.getTexture().loadFromImage(this->map.getImage());
	this->map.getSprite().setTexture(this->map.getTexture());
	this->map.getSprite().setScale(this->window_size.width / this->grand_window_size_width, this->window_size.height / this->grand_windwo_size_height);
	this->map.getSprite().setOrigin(this->map.getImage().getSize().x / 2.f, this->map.getImage().getSize().y / 2.f);
	this->map.getSprite().setPosition(this->window_size.width / 2.f, this->window_size.height / 2.f);
}