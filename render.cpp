#include "Game.h"

void MyNamespace::Game::render()
{
	this->window->clear();

	this->window->setView(*this->view);

	this->window->draw(this->map.getSprite());
	this->window->draw(this->player.getSprite());

	for (int i = 0; i < this->bullet.size(); ++i)
	{
		this->window->draw(this->bullet[i].getSprite());
	}

	for (int i = 0; i < this->enemy.size(); ++i)
	{
		this->window->draw(this->enemy[i].getSprite());
	}

	for (int i = 0; i < this->enemy_bullet.size(); ++i)
	{
		this->window->draw(this->enemy_bullet[i].bullet.getSprite());
	}

	this->window->draw(this->text_kill_score);
	this->window->draw(this->text_damage_score);
	this->window->draw(this->text_health);
	this->window->draw(this->time_text);
	this->window->draw(this->level_text);

	this->window->display();
}