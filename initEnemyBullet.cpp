#include "Game.h"

void MyNamespace::Game::initEnemyBullet()
{
	this->new_enemy_bullet.getImage().loadFromFile("Images/fake_bullet_0.png");
	this->new_enemy_bullet.getImage().createMaskFromColor(sf::Color(255, 255, 255));
	this->new_enemy_bullet.getTexture().loadFromImage(this->new_enemy_bullet.getImage());
	this->new_enemy_bullet.getSprite().setTexture(this->new_enemy_bullet.getTexture());
	this->new_enemy_bullet.getSprite().setScale(this->window_size.width / this->grand_window_size_width, this->window_size.height / this->grand_windwo_size_height);
	this->new_enemy_bullet.getSprite().setOrigin((float)this->new_enemy_bullet.getImage().getSize().x / 2, (float)this->new_enemy_bullet.getImage().getSize().y / 2);

	this->enemy_fire_timer.reserve(100);

	for (int i = 0; i < 100; ++i)
	{
		sf::Clock fire_timer;
		this->enemy_fire_timer.push_back(fire_timer);
	}
}