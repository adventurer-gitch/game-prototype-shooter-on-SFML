#include "Game.h"

void MyNamespace::Game::initWindow()
{
	std::ifstream file0("Config/window.ini");
	
	if (file0.is_open())
	{
		std::getline(file0, this->title);
		file0 >> this->window_size.width >> this->window_size.height;
		file0 >> this->framerate_limit;
		file0 >> this->vertical_sync_enabled;
	}

	file0.close();

	this->window = new sf::RenderWindow(this->window_size, this->title);
	this->window->setFramerateLimit(this->framerate_limit);
	this->window->setVerticalSyncEnabled(this->vertical_sync_enabled);
}