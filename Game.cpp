#include "Game.h"

MyNamespace::Game::Game()
{
	//this->enemy_fire_rate = float(2.f);
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	this->music.openFromFile("Musics/8-bit-gaming-background-music-358443.ogg");
	this->music.play();

	this->buffer.loadFromFile("Sounds/fireball-whoosh-2-179126.ogg");
	this->sound.setBuffer(this->buffer);

	this->initWindow();
	this->initView();
	this->initMap();
	this->initPlayer();
	this->initBullet();
	this->initEnemy();
	this->initEnemyBullet();
	this->initFont();
	this->initTextKillScore();
	this->initTextDamageScore();
	this->initTextHealth();
	this->initTimeText();
	this->initLevel();
}

MyNamespace::Game::~Game()
{
	delete this->window;
}