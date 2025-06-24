#include "Game.h"

void MyNamespace::Game::initPlayer()
{
	std::ifstream open_file0("Data/player.ini");

	int h = 0;
	float d = 0;
	float s = 0;

	if (open_file0.is_open())
	{
		open_file0 >> h;
		open_file0 >> d;
		open_file0 >> s;
	}

	open_file0.close();

	this->player.getImage().loadFromFile("Images/player.png");
	this->player.getTexture().loadFromImage(this->player.getImage());
	this->player.getSprite().setTexture(this->player.getTexture());
	this->player.getSprite().setScale(this->window_size.width / this->grand_window_size_width, this->window_size.height / this->grand_windwo_size_height);
	this->player.getSprite().setTextureRect(sf::IntRect(0, 0, this->grand_player_size_x, this->grand_player_size_y));
	this->player.getSprite().setOrigin(this->player.getImage().getSize().x / 4 / 2, this->player.getImage().getSize().y / 4 / 2);
	this->player.getSprite().setPosition(this->window_size.width / 2, this->window_size.height / 2);
	
	this->player.setHealth(h);
	this->player.setDamage(d);
	this->player.setSpeed(s);
}