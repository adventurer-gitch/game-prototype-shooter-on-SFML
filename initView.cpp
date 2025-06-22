#include "Game.h"

void MyNamespace::Game::initView()
{
	this->view = new sf::View(sf::FloatRect(0, 0, this->window_size.width, this->window_size.height));
	this->window->setView(*this->view);
}