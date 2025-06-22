#include "Game.h"

void MyNamespace::Game::initTextKillScore()
{
	this->text_kill_score.setFont(this->font);
	this->text_kill_score.setCharacterSize(20);
	this->text_kill_score.setFillColor(sf::Color(255, 255, 255));
}

void MyNamespace::Game::initTextDamageScore()
{
	this->text_damage_score.setFont(this->font);
	this->text_damage_score.setCharacterSize(20);
	this->text_damage_score.setFillColor(sf::Color(255, 255, 255));
}

void MyNamespace::Game::initTextHealth()
{
	this->text_health.setFont(this->font);
	this->text_health.setCharacterSize(20);
	this->text_health.setFillColor(sf::Color(255, 255, 255));
}

void MyNamespace::Game::initTimeText()
{
	this->time_text.setFont(this->font);
	this->time_text.setCharacterSize(20);
	this->time_text.setFillColor(sf::Color(255, 255, 255));
}

void MyNamespace::Game::initLevel()
{
	this->level_text.setFont(this->font);
	this->level_text.setCharacterSize(20);
	this->level_text.setFillColor(sf::Color(255, 255, 255));
}