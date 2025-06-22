#include "Game.h"

void MyNamespace::Game::initEnemy()
{
	std::ifstream open_file0("Data/Enemy.ini");

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

	this->enemy.reserve(100);
	this->enemy_fire_timer.reserve(100);

	this->new_enemy.getImage().loadFromFile("Images/skeleton.png");
	//this->new_enemy.getImage().createMaskFromColor(sf::Color(153, 229, 80));
	this->new_enemy.getTexture().loadFromImage(this->new_enemy.getImage());
	this->new_enemy.getSprite().setTexture(this->new_enemy.getTexture());
	this->new_enemy.getSprite().setScale(this->window_size.width / this->grand_window_size_width, this->window_size.height / this->grand_windwo_size_height);
	this->new_enemy.getSprite().setTextureRect(sf::IntRect(0, this->grand_enemy_size_y, this->grand_enemy_size_x, this->grand_enemy_size_y));
	this->new_enemy.getSprite().setOrigin((float)this->new_enemy.getImage().getSize().x / 2, (float)this->new_enemy.getImage().getSize().y / 2);

	sf::Clock fire_timer;
	this->enemy_fire_timer.push_back(fire_timer);

	this->new_enemy.setHealth(h);
	this->new_enemy.setDamage(d);
	this->new_enemy.setSpeed(s);
}